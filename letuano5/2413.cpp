#include <bits/stdc++.h>
using namespace std;

// dp[i][0] = last blocks are separate | || |
//                                   _ _
// dp[i][1] = last blocks are fused |   |

// transition:
//              _  _    _  _    _  _    _  _     _ _
//  _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
// | || | =>   | || |, | || |, | || |, | || |,  | | |
//              _ _    _ _    _ _
//  _ _        |   |  |_|_|  |_ _|
// |   |  =>   |   |, |   |, |   |

const int mod = 1e9 + 7;
long long f[1000005][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  f[1][0] = f[1][1] = 1;
  for (int i = 2; i <= 1e6; i++) {
    f[i][0] = f[i - 1][1] + f[i - 1][0] * 4;
    f[i][1] = f[i - 1][1] * 2 + f[i - 1][0];

    f[i][0] %= mod;
    f[i][1] %= mod;
  }

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    cout << (f[n][0] + f[n][1]) % mod << "\n";
  }

  return 0;
}
