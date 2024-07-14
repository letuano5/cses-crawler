#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

bitset <N> dp[N];
bitset <N> done;
vector <int> g[N];

void dfs (int u) {
  if (done[u])
    return;
  done[u] = true;
  dp[u][u] = 1;
  for (int v: g[u]) {
    dfs(v);
    dp[u] |= dp[v];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
  }

  for (int u = 1; u <= n; u++)
    if (!done[u]) dfs(u);

  for (int u = 1; u <= n; u++)
    cout << dp[u].count() << " ";

  return 0;
}
