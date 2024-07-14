#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int L = __lg(N) + 5;

int n, q;
int par[N][L];
int h[N];
vector <int> g[N];

void dfs (int u) {
  for (int i = 0; par[par[u][i]][i]; i++) {
    par[u][i + 1] = par[par[u][i]][i];
  }

  for (int v: g[u]) {
    h[v] = h[u] + 1;
    par[v][0] = u;
    dfs(v);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    g[p].push_back(i);
  }

  h[1] = 1;
  dfs(1);

  while (q--) {
    int x, k;
    cin >> x >> k;
    if (k >= h[x]) {
      cout << -1 << "\n";
      continue;
    }
    for (int i = L - 1; i >= 0; i--)
      if (k >> i & 1)
        x = par[x][i];
    cout << x << "\n";
  }

  return 0;
}
