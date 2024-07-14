#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  int j = 1;
  int ans = 0;
  int mod = 1e9 + 7;

  auto sum = [&] (int x) -> int {
    if (x % 2 == 0)
      return (x / 2 % mod) * ((x + 1) % mod) % mod;
    return (x % mod) * ((x + 1) / 2 % mod) % mod;
  };

  #define s(l, r) ((sum(r) - sum(l-1) + mod) % mod)

  while (j <= n) {
    int val = n / j;
    int nxt = n / val;

    (ans += (val % mod) * s(j, nxt) % mod) %= mod;

    j = nxt + 1;
  }

  cout << ans;
  return 0;
}
