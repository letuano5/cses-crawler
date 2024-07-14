#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int LG = __lg(N) + 5;

int n, m;
vector<int> g[N];
int f[N][LG];
int h[N];
int cnt[N];

void dfs(int u) {
  for (int i = 0; f[f[u][i]][i]; i++) {
    f[u][i + 1] = f[f[u][i]][i];
  }
  for (int v : g[u]) {
    if (v == f[u][0]) {
      continue;
    }
    h[v] = h[u] + 1;
    f[v][0] = u;
    dfs(v);
  }
}

int lca(int u, int v) {
  if (h[u] < h[v]) {
    swap(u, v);
  }

  for (int dist = h[u] - h[v]; dist > 0; ) {
    u = f[u][__lg(dist)];
    dist = h[u] - h[v];
  }

  if (u == v) {
    return u;
  }

  for (int i = __lg(h[u]); i >= 0; i--) {
    if (f[u][i] != f[v][i]) {
      u = f[u][i];
      v = f[v][i];
    }
  }

  return f[u][0];
}

void dfs_push(int u) {
  for (int v : g[u]) {
    if (v == f[u][0]) {
      continue;
    }
    dfs_push(v);
    cnt[u] += cnt[v];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  h[1] = 1;
  dfs(1);

  while (m--) {
    int u, v;
    cin >> u >> v;
    int p = lca(u, v);
    cnt[u]++;
    cnt[v]++;
    cnt[p]--;
    cnt[f[p][0]]--;
  }

  dfs_push(1);

  for (int u = 1; u <= n; u++) {
    cout << cnt[u] << " ";
  }

  return 0;
}
