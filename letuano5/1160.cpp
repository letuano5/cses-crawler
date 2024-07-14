#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LG = 20;

int n, q;
int nxt[N];

vector <int> adj[N], radj[N];
int f[N][LG];

int id_comp[N];
int cnt_comp;
int timer[N];
int d[N];
int root_cycle[N];
int pos_in_cycle[N];
int size_cycle[N];

void read_input() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> nxt[i];
//    cerr << i << " " << nxt[i] << endl;
    adj[i].push_back(nxt[i]);
    radj[nxt[i]].push_back(i);
  }
}

void find_cycle() {
  for (int i = 1; i <= n; i++)
    d[i] = -1;

  for (int i = 1; i <= n; i++) {
    if (id_comp[i])
      continue;

    ++cnt_comp;

    vector <int> path;

    int u = i;
    while (timer[u] != cnt_comp) {
      timer[u] = cnt_comp;
      path.push_back(u);
      u = nxt[u];
    }

    int cycle_start = u;
    int pos = find(path.begin(), path.end(), cycle_start) - path.begin();

    queue <pair <int, int>> qu;

//    cerr << "current cycle : \n";

    for (int j = pos; j < (int)path.size(); j++) {
//      cerr << path[j] << " ";
      int u = path[j];
      id_comp[u] = cnt_comp;
      root_cycle[u] = u;
      d[u] = 0;
      pos_in_cycle[u] = j - pos + 1;
      size_cycle[u] = path.size() - pos;
      qu.emplace(u, u);
    }

//    cerr << "\n----\n";

    while (!qu.empty()) {
      auto [u, root] = qu.front();
      qu.pop();

      for (int v : radj[u]) {
        if (d[v] == -1) {
          d[v] = d[u] + 1;
          root_cycle[v] = root;
          id_comp[v] = cnt_comp;
//          cerr << "ahihi " << u << " " << v << endl;
          f[v][0] = u;
          qu.emplace(v, root);
        }
      }
    }
  }
}

void build_spt() {
  for (int k = 1; k < LG; k++)
    for (int i = 1; i <= n; i++)
      f[i][k] = f[f[i][k - 1]][k - 1];
}

int jump (int u, int k) {
  for (int i = LG - 1; i >= 0; i--)
    if (k >> i & 1) {
      u = f[u][i];
    }
  return u;
}

bool in_cycle (int u) {
  return pos_in_cycle[u] != 0;
}

int dist (int u, int v) {
  if (id_comp[u] != id_comp[v])
    return -1;

  if (!in_cycle(u) && !in_cycle(v)) {
//    cerr << u << " " << v << " " << d[u] << " " << d[v] << endl;
    if (d[v] > d[u])
      return -1;
//    cerr << u << " " << f[u][0] << endl;
    if (jump(u, d[u] - d[v]) != v)
      return -1;
    return d[u] - d[v];
  }

  if (in_cycle(u) && !in_cycle(v)) {
//    cerr << "???";
    return -1;
  }

  if (!in_cycle(u) && in_cycle(v)) {
    int ans = d[u];
    u = root_cycle[u];

    int pos_u = pos_in_cycle[u];
    int pos_v = pos_in_cycle[v];
    if (pos_u <= pos_v)
      ans += pos_v - pos_u;
    else ans += size_cycle[u] - pos_u + pos_v;

    return ans;
  }

  if (in_cycle(u) && in_cycle(v)) {
    int pos_u = pos_in_cycle[u];
    int pos_v = pos_in_cycle[v];
    if (pos_u <= pos_v)
      return pos_v - pos_u;
    return size_cycle[u] - pos_u + pos_v;
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

//  freopen("input.txt", "r", stdin);

  read_input();
  find_cycle();
  build_spt();

  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << dist(u, v) << "\n";
  }

  return 0;
}
