#pragma GCC optimize ("Ofast,unroll-loops,-ffloat-store")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

bitset <3005> a[3005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    for (int j = 0; j < n; j++)
      a[i][j + 1] = s[j] - '0';
  }

  long long ans = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int cnt = (a[i] & a[j]).count();
      ans += 1ll * cnt * (cnt - 1) / 2;
    }
  }

  cout << ans;
  return 0;
}
