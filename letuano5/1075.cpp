#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1005;

int64_t f[N][N][3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k; cin >> n;
  f[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int t = 0; t <= 2; t++) {
        (f[i + 1][j + 1][2] += f[i][j][t]) %= MOD;
        (f[i + 1][j][1] += f[i][j][t] * (2 * j - t)) %= MOD;
        if (j - t >= 0 && j - 1 >= 0) (f[i + 1][j - 1][0] += f[i][j][t] * (j - t) * (j - 1)) %= MOD;
      }
    }
  }

  int64_t ans = 0;

  cout << (f[n][1][0] + f[n][1][1] + f[n][1][2]) % MOD;

//  cerr << f[n][k][0] << " " << f[n][k][1] << " " << f[n][k][2] << endl;

//  cout << f[n][k][0] + f[n][k][1] + f[n][k][2];

  return 0;
}
