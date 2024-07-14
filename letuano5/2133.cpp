#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int ADD = 1;
const int REMOVE = 2;

struct Query {
  int id_e;
  int tin, tout;
  bool ask;

  Query (int id = 0, int in = 0, int out = 0, bool a = 0) {
    id_e = id;
    tin = in;
    tout = out;
    ask = a;
  }
};

pair<int, int> edges[N];
map<pair<int, int>, int> id_edges;
vector<int> rem[N];
int ans[N];
int num_edges;
Query qq[N];

int get_id (int u, int v) {
  if (u > v) {
    swap(u, v);
  }
  if (!id_edges.count({u, v})) {
    int new_id = ++num_edges;
    edges[new_id] = {u, v};
    id_edges[{u, v}] = new_id;
  }
  return id_edges[{u, v}];
}

struct DSU {
  int par[N];
  int cc;

  // u, v, pu, pv, comp
  vector<tuple<int, int, int, int, int>> info;

  DSU (int n = 0) {
    memset(par, -1, sizeof(par));
    cc = n;
  }

  int root (int u) {
    if (par[u] < 0) {
      return u;
    }
    return root(par[u]);
  }

  bool join (int u, int v) {
    u = root(u);
    v = root(v);

    info.emplace_back(u, v, par[u], par[v], cc);

    if (u == v) {
      return false;
    }
    if (par[u] > par[v]) {
      swap(u, v);
    }
    cc--;
    par[u] += par[v];
    par[v] = u;
    return true;
  }

  void rollback (int turn) {
    while (turn--) {
      auto [u, v, pu, pv, comp] = info.back();
      info.pop_back();
      cc = comp;
      par[u] = pu;
      par[v] = pv;
    }
  }
};

struct SegTree {
  DSU dsu;
  vector<int> st[4 * N];

  SegTree (int n = 0) {
    dsu = DSU(n);
  }

  void add (int id, int l, int r, int u, int v, int e) {
    if (v < l || r < u) {
      return;
    }
    if (u <= l && r <= v) {
      st[id].emplace_back(e);
      return;
    }
    int mid = (l + r) >> 1;
    add(id << 1, l, mid, u, v, e);
    add(id << 1 | 1, mid + 1, r, u, v, e);
  }

  void dfs (int id, int l, int r) {
    for (int id_e : st[id]) {
      auto [u, v] = edges[id_e];
      dsu.join(u, v);
    }

    if (l == r) {
      if (qq[l].ask)
        ans[l] = dsu.cc;
    }
    else {
      int mid = (l + r) >> 1;
      dfs(id << 1, l, mid);
      dfs(id << 1 | 1, mid + 1, r);
    }

    dsu.rollback(st[id].size());
  }
};

SegTree st;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

//  freopen("input.txt", "r", stdin);

  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    int e = get_id(u, v);
    qq[i] = Query(e, -1, -1, i == m);
    rem[e].emplace_back(i);
  }

  st = SegTree(n);

  for (int i = m + 1; i <= m + q; i++) {
    int t, u, v;
    cin >> t >> u >> v;

    int e = get_id(u, v);

    if (t == ADD) {
      qq[i] = Query(e, -1, -1, 1);
      rem[e].emplace_back(i);
    }
    else {
      int tin = -1, tout = -1;
      if (!rem[e].empty()) {
        tout = i;
        tin = rem[e].back();
        rem[e].pop_back();
      }
      qq[i] = Query(e, tin, tout, 1);
    }
  }

  q += m;

  for (int e = 1; e <= num_edges; e++) {
    while (!rem[e].empty()) {
      int tin = rem[e].back();
      rem[e].pop_back();
      int tout = ++q;
      qq[q] = Query(e, tin, tout, 0);
    }
  }

  for (int i = 1; i <= q; i++) {
    if (qq[i].tin == -1 || qq[i].tout == -1) {
      continue;
    }
    st.add(1, 1, q, qq[i].tin, qq[i].tout - 1, qq[i].id_e);
  }

  st.dfs(1, 1, q);

  for (int i = 1; i <= q; i++) {
    if (qq[i].ask) {
      cout << ans[i] << " ";
    }
  }

  return 0;
}
