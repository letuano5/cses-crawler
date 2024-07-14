#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

void debug_out() { cerr << '\n'; }
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
  cerr << " " << H;
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int n, m, q;
vector <int> g[N];
vector <int> ng[N];

int time_dfs, num_scc;
stack <int> st;
int scc[N];
int low[N];
int num[N];

int done[N];
vector <int> topo;
bitset <N> dp[N];

void dfs (int u, int par = -1) {
  low[u] = num[u] = ++time_dfs;
  st.push(u);
  for (int v: g[u]) {
    if (v == par)
      continue;
    if (scc[v])
      continue;
    if (num[v])
      low[u] = min(low[u], num[v]);
    else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    }
  }

  if (low[u] >= num[u]) {
    ++num_scc;
    int v;
    do {
      v = st.top();
      st.pop();
      scc[v] = num_scc;
    } while (v != u);
  }
}

void dfs_topo (int u) {
  done[u] = 1;
  for (int v: ng[u]) {
//    if (done[v] == 1) debug(u, v, done[v]);
//    assert(done[v] != 1);
    if (!done[v]) dfs_topo(v);
  }
  topo.push_back(u);
  done[u] = 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> q;
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  for (int u = 1; u <= n; u++)
    if (!num[u])
      dfs(u);

  for (int u = 1; u <= n; u++) {
    for (int v: g[u])
      if (scc[u] != scc[v])
        ng[scc[u]].push_back(scc[v]);
  }

//  for (int u = 1; u <= n; u++)
//    debug(u, scc[u]);
  for (int u = 1; u <= num_scc; u++)
    if (!done[u]) dfs_topo(u);

  for (int i = 0; i < topo.size(); i++) {
    int u = topo[i];
    dp[u][u] = 1;
    for (int v : ng[u])
      dp[u] |= dp[v];
  }

//  for (int u: topo) debug(u);

//  debug(num_scc);

  while (q--) {
    int a, b;
    cin >> a >> b;
    if (scc[a] == scc[b] || dp[scc[a]][scc[b]]) {
      cout << "YES\n";
    }
    else cout << "NO\n";
  }

  return 0;
}
