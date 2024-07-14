#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

struct Edge {
  int u, v;
  Edge (int _u = 0, int _v = 0) {
    u = _u, v = _v;
  }
};

struct Operator {
  int u, v, par_u, par_v;
  Operator (int _u = 0, int _v = 0, int _pu = 0, int _pv = 0) {
    u = _u;
    v = _v;
    par_u = _pu;
    par_v = _pv;
  }
};

struct DSU {
  vector <int> par;
  vector <Operator> oper;

  DSU (int _n = 0) {
    par.assign(_n + 5, -1);
  }

  int root (int u) {
    if (par[u] < 0)
      return u;
    return par[u] = root(par[u]);
  }

  int size (int u) {
    return -par[root(u)];
  }

  bool join (int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v)
      return false;
    oper.push_back(Operator(u, v, par[u], par[v]));
    if (par[u] > par[v])
      swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
  }
  void rollback() {
    while (!oper.empty()) {
      auto [u, v, pu, pv] = oper.back();
      oper.pop_back();
      par[u] = pu;
      par[v] = pv;
    }
  }
};

int n, m, q;
Edge edges[N];
Edge queries[N];
DSU ds(N);
int low[N];
int high[N];
int ans[N];
vector <int> queue_queries[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    edges[i] = {u, v};
  }
  for (int i = 1; i <= q; i++) {
    low[i] = 1,
    high[i] = m;
    ans[i] = -1;
    int u, v; cin >> u >> v;
    if (u == v)
      high[i] = 0,
      ans[i] = 0;
    queries[i] = {u, v};
  }

  for (int steps = 0; steps <= __lg(m) + 5; steps++) {
    for (int i = 1; i <= q; i++)
      if (low[i] <= high[i])
        queue_queries[(low[i] + high[i]) / 2].push_back(i);

    for (int i = 1; i <= m; i++) {
      auto [u, v] = edges[i];
      ds.join(u, v);
      while (!queue_queries[i].empty()) {
        int qq = queue_queries[i].back();
        queue_queries[i].pop_back();
        auto [a, b] = queries[qq];
        if (ds.root(a) == ds.root(b))
          ans[qq] = i,
          high[qq] = i - 1;
        else
          low[qq] = i + 1;
      }
    }
    ds.rollback();
  }

  for (int i = 1; i <= q; i++)
    cout << ans[i] << "\n";

  return 0;
}
