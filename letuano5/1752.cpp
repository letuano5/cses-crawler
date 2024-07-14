#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LG = __lg(N) + 5;

int n, d;
vector<int> g[N];
set<pair<int, int>> s[N];
int f[N][LG];
int h[N];
int best = 0;

void dfs_lca (int u, int par = -1) {
  for (int i = 0; f[f[u][i]][i]; i++) {
    f[u][i + 1] = f[f[u][i]][i];
  }
  for (int v : g[u]) {
    if (v == par) {
      continue;
    }
    f[v][0] = u;
    h[v] = h[u] + 1;
    dfs_lca(v, u);
  }
}

#define lg(x) ((x) > 0 ? __lg(x) : -1)

int lca (int u, int v) {
  if (h[u] < h[v]) {
    swap(u, v);
  }
  for (int dist = h[u] - h[v]; dist > 0; dist = h[u] - h[v]) {
    u = f[u][__lg(dist)];
  }
  if (u == v) {
    return u;
  }
  for (int i = lg(h[u]); i >= 0; i--) {
    if (f[u][i] != f[v][i]) {
      u = f[u][i];
      v = f[v][i];
    }
  }
  return f[u][0];
}

void dfs (int u, int par = -1) {
  for (int v : g[u]) {
    if (v == par) {
      continue;
    }
    dfs(v, u);
    if (s[u].size() < s[v].size()) {
      s[u].swap(s[v]);
    }
    for (auto [hp, p] : s[v]) {
      s[u].emplace(hp, p);
    }
    s[v].clear();
  }

  while (s[u].size() >= 2) {
    auto it = s[u].begin();
    auto [hv1, v1] = *it;
    advance(it, 1);
    auto [hv2, v2] = *it;
    if (hv1 + hv2 - 2 * h[lca(v1, v2)] < d) {
      s[u].erase(s[u].begin());
    }
    else {
      break;
    }
  }

  if (s[u].size()) {
    if (s[u].begin()->first - h[u] >= d) {
      s[u].emplace(h[u], u);
    }
  }
  else {
    s[u].emplace(h[u], u);
  }

  best = max(best, (int)s[u].size());
//  if (s[u].size() == 2) {
//    cerr << "OK " << u << endl;
//    for (auto [hv, v] : s[u]) {
//      cerr << hv << " " << v << endl;
//    }
//  }
}


void dfs_trace (int u, int par = -1) {
  for (int v : g[u]) {
    if (v == par) {
      continue;
    }
    dfs_trace(v, u);
    if (s[u].size() < s[v].size()) {
      s[u].swap(s[v]);
    }
    for (auto [hp, p] : s[v]) {
      s[u].emplace(hp, p);
    }
    s[v].clear();
  }

  while (s[u].size() >= 2) {
    auto it = s[u].begin();
    auto [hv1, v1] = *it;
    advance(it, 1);
    auto [hv2, v2] = *it;
//    if (u == 3) cerr << v1 << " " << v2 << " " << hv1 << " " << hv2 << " " << hv1 + hv2 - h[lca(v1, v2)] << endl;
    if (hv1 + hv2 - 2 * h[lca(v1, v2)] < d) {
      s[u].erase(s[u].begin());
    }
    else {
      break;
    }
  }

  if (s[u].size()) {
    if (s[u].begin()->first - h[u] >= d) {
      s[u].emplace(h[u], u);
    }
  }
  else {
    s[u].emplace(h[u], u);
  }

  if ((int)s[u].size() == best) {
    for (auto [hv, v] : s[u]) {
      cout << v << " ";
    }
    exit(0);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> d;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  dfs_lca(1);
  dfs(1);

  cout << best << "\n";

  for (int u = 1; u <= n; u++) {
    s[u].clear();
  }
  dfs_trace(1);

  return 0;
}
