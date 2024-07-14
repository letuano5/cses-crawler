#include <bits/stdc++.h>

using namespace std;

namespace std {
#ifndef LOCAL
#define cerr \
  if (0) cerr
#endif
}  // namespace std

// 1-indexed
// 1...n: = 1
// n + 1 ... 2n = 0
struct two_sat {
  int n;
  vector<vector<int>> adj;
  vector<int> low, num;
  vector<int> status;
  int time_dfs;
  stack<int> st;
  vector<int> comp;
  int num_comp;

  two_sat(int n = 0) : n(n) {
    st = stack<int>();
    time_dfs = num_comp = 0;
    adj.assign(2 * n + 5, vector<int>());
    low.assign(2 * n + 5, 0);
    num.assign(2 * n + 5, 0);
    comp.assign(2 * n + 5, 0);
  }

  void add_edge(int a, int b) {
    // cerr << a << " " << b << " " << adj.size() << endl;
    adj[a].push_back(b);
  }

  // (u == f) OR (v == g)
  // x OR y <=> ((!x -> y) AND (!y -> x))
  void add_or(int u, int f, int v, int g) {
    add_edge(u + (f ? n : 0), v + (g ? 0 : n));
    add_edge(v + (g ? n : 0), u + (f ? 0 : n));
  }

  void add_xor(int u, int f, int v, int g) {
    add_or(u, f, v, g);
    add_or(u, !f, v, !g);
  }

  void add_and(int u, int f, int v, int g) {
    add_xor(u, !f, v, g);
  }

  void dfs(int u) {
    // cerr << "check " << u << endl;
    low[u] = num[u] = ++time_dfs;
    st.emplace(u);
    for (int v : adj[u]) {
      if (!num[v]) {
        dfs(v);
        low[u] = min(low[u], low[v]);
      } else {
        low[u] = min(low[u], num[v]);
      }
    }
    if (low[u] >= num[u]) {
      int v;
      ++num_comp;
      do {
        v = st.top();
        st.pop();
        comp[v] = num_comp;
        low[v] = num[v] = 1e9;
      } while (v != u);
    }
  }

  vector<int> solve() {
    for (int i = 1; i <= 2 * n; i++) {
      if (!num[i]) dfs(i);
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
      if (comp[i] == comp[i + n]) {
        return vector<int>();
      }
      ans[i] = comp[i] < comp[i + n];
    }
    return ans;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
#define task "a"
#else
#define task ""
#endif
  if (fopen(task ".inp", "r")) {
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
  }
  int n, m;
  cin >> n >> m;
  two_sat solver(m);
  for (int _ = 1; _ <= n; _++) {
    char c[2];
    int u[2];
    for (int i = 0; i < 2; i++) {
      cin >> c[i] >> u[i];
    }
    // cerr << c[0] << " " << u[0] << " " << c[1] << " " << u[1] << endl;
    solver.add_or(u[0], c[0] == '+', u[1], c[1] == '+');
  }
  vector<int> ans = solver.solve();
  if (ans.empty()) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  for (int u = 1; u <= m; u++) cout << (ans[u] ? '+' : '-') << " ";
  return 0;
}