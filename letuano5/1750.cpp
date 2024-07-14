#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LG = 31;

int f[N][LG];
int n, q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;

  for (int i = 1; i <= n; i++)
    cin >> f[i][0];

  for (int k = 1; k < LG; k++) {
    for (int i = 1; i <= n; i++)
      f[i][k] = f[f[i][k - 1]][k - 1];
  }

  while (q--) {
    int u, k;
    cin >> u >> k ;
    for (int i = LG - 1; i >= 0; i--)
      if (k >> i & 1) u = f[u][i];
    cout << u << "\n";
  }

  return 0;
}
