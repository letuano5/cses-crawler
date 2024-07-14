#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  int ord = n * n / 2 + 1;

  auto ok = [&] (int x) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += min((x - 1) / i, n);
    }
    return cnt < ord;
  };

  int low = 1, high = 1e12;
  int ans = 0;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (ok(mid)) {
      ans = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }

  cout << ans;
  return 0;
}
