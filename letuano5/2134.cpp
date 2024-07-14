#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LG = __lg(N) + 5;

int n, q;
int a[N];
vector<int> g[N];
int sz[N];

int par[N];
int h[N];
int head_chain[N];
int num_chain = 1;
int id_chain[N];
int tin[N], tout[N], time_dfs;
int st[2 * N];

void dfs_sz (int u) {
  sz[u] = 1;
  for (int v : g[u]) {
    if (v == par[u])
      continue;
    h[v] = h[u] + 1;
    par[v] = u;
    dfs_sz(v);
    sz[u] += sz[v];
  }
}

void dfs_hld (int u) {
  if (!head_chain[num_chain])
    head_chain[num_chain] = u;
  id_chain[u] = num_chain;
  tin[u] = ++time_dfs;

  int max_child = -1;
  for (int v : g[u]) {
    if (v == par[u])
      continue;
    if (max_child == -1 || sz[v] > sz[max_child])
      max_child = v;
  }

  if (max_child != -1) {
    dfs_hld(max_child);
  }

  for (int v : g[u]) {
    if (v == par[u] || v == max_child) {
      continue;
    }
    ++num_chain;
    dfs_hld(v);
  }

  tout[u] = time_dfs;
}

inline void update(int pos, int value) {
  for (st[pos += n] = value; pos > 1; pos >>= 1)
    st[pos >> 1] = max(st[pos], st[pos ^ 1]);
}

inline int get(int l, int r) {
  if (l > r)
    swap(l, r);
  r++;

  int res = 0;

  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      res = max(res, st[l++]);
    if (r & 1)
      res = max(res, st[--r]);
  }

  return res;
}

//void update (int id, int l, int r, int pos, int val) {
//  if (pos < l || pos > r)
//    return;
//  if (l == r) {
//    st[id] = val;
//    return;
//  }
//  int mid = (l + r) >> 1;
//  update(id << 1, l, mid, pos, val);
//  update(id << 1 | 1, mid + 1, r, pos, val);
//  st[id] = max(st[id << 1], st[id << 1 | 1]);
//}
//
//int get (int id, int l, int r, int u, int v) {
//  if (v < l || r < u)
//    return 0;
//  if (u <= l && r <= v)
//    return st[id];
//  int mid = (l + r) >> 1;
//  return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
//}
//
//int get (int l, int r) {
//  if (l > r)
//    swap(l, r);
//  return get(1, 1, n, l, r);
//}

int query (int u, int v) {
  int ans = 0;
  while (true) {
    if (!u || !v)
      break;
    if (id_chain[u] == id_chain[v]) {
      ans = max(ans, get(tin[u], tin[v]));
      break;
    }
    int headu = head_chain[id_chain[u]], headv = head_chain[id_chain[v]];
    if (h[headu] < h[headv]) {
      swap(headu, headv);
      swap(u, v);
    }
    ans = max(ans, get(tin[headu], tin[u]));
    u = par[headu];
  }
  return ans;
}

void update (int u) {
  update(tin[u], a[u]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

//  freopen("test_input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  h[1] = 1;
  dfs_sz(1);
  dfs_hld(1);

//  build(1, 1, n);
//  for (int u = 1; u <= n; u++) {
//    cerr << u << " " << id_chain[u] << "\n";
//  }

  for (int u = 1; u <= n; u++) update(u);

//  cerr << query(5, 1) << endl;
//  return 0;

  while (q--) {
    int t;
    cin >> t;

    if (t == 2) {
      int u, v;
      cin >> u >> v;
      cout << query(u, v) << "\n";
//      int lca = get_lca(u, v);
//      cout << max(query(u, lca), query(v, lca)) << "\n";
    }

    else {
      int u, val;
      cin >> u >> val;
      a[u] = val;
      update(u);
    }
  }

  return 0;
}
