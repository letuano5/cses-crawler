#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

// int res = -1e9, h[N];
int f[N], d[N];
vector<int> g[N];
bool vst[N];

void dfs(int u) {
  vst[u] = 1;
  int mx0 = -1, mx1 = -1;
  for (int v : g[u])
    if (!vst[v]) {
      // if (u == 1) cerr << "?" << v << endl;
      dfs(v);
      if (mx0 < f[v]) {
        mx1 = max(mx1, mx0);
        mx0 = f[v];
      } else {
        mx1 = max(mx1, f[v]);
      }
      f[u] = max(f[u], f[v] + 1);
    }
  // if (u == 1) cerr << mx0 << " " << mx1 << endl;
  if (mx1 >= 0)
    d[u] = mx0 + mx1 + 2;
  else
    d[u] = mx0 + 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#define task "a"
  if (fopen(task ".inp", "r")) {
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
  }

  int n;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1);

  cout << *max_element(d + 1, d + n + 1);
  return 0;
}