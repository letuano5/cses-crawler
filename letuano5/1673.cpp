#include <bits/stdc++.h>
using namespace std;
 
const int N = 2505;
 
int n, m;
vector <tuple <int, int, int>> edges;
long long d[N];
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  cin >> n >> m;
 
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.emplace_back(u, v, -w);
//    g[u].emplace_back(v, -w);
  }
 
  for (int u = 1; u <= n; u++) {
    d[u] = 1e18;
  }
  d[1] = 0;
 
  for (int turn = 1; turn < n; turn++) {
    for (auto [u, v, w] : edges) {
      if (d[u] != 1e18 && d[v] > d[u] + w) {
        d[v] = d[u] + w;
      }
    }
  }
 
  for (int turn = 0; turn < n; turn++) {
    for (auto [u, v, w] : edges) {
      if (d[u] != 1e18 && d[v] > d[u] + w) {
        d[v] = -1e18;
      }
    }
  }
 
  if (d[n] == -1e18) {
    cout << -1;
  }
  else cout << -d[n];
 
  return 0;
}