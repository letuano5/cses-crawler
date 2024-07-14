#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k;
vector <int> g[N];
int cnt[N];
int child[N];
int timer[N], time_dfs;
bool deleted[N];
long long ans = 0;

void read_input() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}

void dfs_sz (int u, int par = -1) {
  child[u] = 1;
  for (int v : g[u]) {
    if (v == par)
      continue;
    if (deleted[v])
      continue;
    dfs_sz(v, u);
    child[u] += child[v];
  }
}

int find_centroid (int u, int n, int par = -1) {
  for (int v : g[u]) {
    if (v == par)
      continue;
    if (deleted[v])
      continue;
    if (child[v] * 2 > n)
      return find_centroid(v, n, u);
  }
  return u;
}

int max_dep = 0;

void calc (int u, int h, bool rec, int par = -1) {
  if (h > k)
    return;
  max_dep = max(max_dep, h);
  if (!rec) {
    ans += cnt[k - h];
  }
  else cnt[h]++;

  for (int v : g[u]) {
    if (v == par)
      continue;
    if (deleted[v])
      continue;
    calc(v, h + 1, rec, u);
  }
}

void decompose (int u) {
  dfs_sz(u);

  int cen = find_centroid(u, child[u]);
  u = cen;

  fill(cnt, cnt + max_dep + 1, 0);
  max_dep = 0;

  deleted[u] = true;
  ++cnt[0];

  for (int v : g[u]) {
    if (deleted[v])
      continue;
    calc(v, 1, false, u);
    calc(v, 1, true, u);
  }

  for (int v : g[u]) {
    if (deleted[v])
      continue;
    decompose(v);
  }
}

void solve() {
  decompose(1);
  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

//  freopen("test_input.txt", "r", stdin);

  read_input();
  solve();

  return 0;
}
