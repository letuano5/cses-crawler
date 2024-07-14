#include <bits/stdc++.h>

using namespace std;

#define int int64_t

namespace std {
#ifndef LOCAL
#define cerr \
  if (0) cerr
#endif
}  // namespace std

int p[1000005];
int cnt[1000005];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
#define task "a"
#else
#define task ""
#endif
//  if (fopen(task ".inp", "r")) {
//    freopen(task ".inp", "r", stdin);
//    freopen(task ".out", "w", stdout);
//  }
  iota(p, p + 1000001, 0);
  for (int i = 2; i * i <= 1e6; i++) {
    if (p[i] == i) {
      for (int j = i * i; j <= 1e6; j += i) {
        if (p[j] == j) {
          p[j] = i;
        }
      }
    }
  }
  // for (int i = 2; i <= 20; i++) {
  //   cerr << i << ": " << p[i] << endl;
  // }
  int tc;
  cin >> tc;
  int64_t ans = 0;
  while (tc--) {
//    int t;
//    cin >> t;
    int delta = 1;
    int x;
    cin >> x;
    vector<int> P;
    while (x > 1) {
      int cur = p[x];
      while (x % cur == 0) x /= cur;
      P.push_back(cur);
    }
    for (int mask = 0; mask < 1 << P.size(); ++mask) {
      int cur = 1;
      for (int i = 0; i < P.size(); i++) {
        if (mask >> i & 1) cur *= P[i];
      }
      if (__builtin_popcount(mask) & 1) {
        ans -= cnt[cur] * delta;
      } else {
        ans += cnt[cur] * delta;
      }
      cnt[cur] += delta;
    }
//    cout << ans << "\n";
  }
  cout << ans;
  return 0;
}
