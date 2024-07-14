#include <bits/stdc++.h>
using namespace std;

using TNode = tuple<int64_t, int, int>;
const int N = 1e5 + 5;

vector<pair<int, int>> g[N];
int64_t f[N][2];
int n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  while (m--) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].emplace_back(v, c);
  }

  memset(f, 0x3f, sizeof(f));

  priority_queue<TNode, vector<TNode>, greater<TNode>> pq;
  pq.emplace(0, 1, 0);
  f[1][0] = 0;

  while (!pq.empty()) {
    auto [du, u, used] = pq.top();
    pq.pop();

    if (f[u][used] != du) {
      continue;
    }

    if (u == n) {
      cout << du;
      return 0;
    }

    for (auto [v, c] : g[u]) {
      if (f[v][used] > f[u][used] + c) {
        f[v][used] = f[u][used] + c;
        pq.emplace(f[v][used], v, used);
      }
      if (!used && f[v][1] > f[u][0] + c / 2) {
        f[v][1] = f[u][0] + c / 2;
        pq.emplace(f[v][1], v, 1);
      }
    }
  }

  return 0;
}
