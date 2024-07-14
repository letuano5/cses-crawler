#include <bits/stdc++.h>
using namespace std;

long long f[20][10];
int a[20];
int n;

long long dp (int i, bool smaller, bool zero, int last) {
  if (i < 0)
    return 1;

  if (smaller == 1 && zero == 0 && f[i][last] != -1)
    return f[i][last];

  long long ans = 0;
  int maxd = smaller ? 9 : a[i];
  for (int d = 0; d <= maxd; d++) {
    bool nsml = smaller || d < maxd;
    bool nzero = zero && i >= 1 && d == 0;
    int nlast = -1;
    if (!nzero) nlast = d;
    if (last != -1 && nlast == last) {
      continue;
    }
    ans += dp(i - 1, nsml, nzero, nlast);
  }

  return smaller == 1 && zero == 0 ? f[i][last] = ans : ans;
}

long long sol (long long x) {
  if (x < 0)
    return 0;
  n = 0;
  do {
    a[n++] = x % 10;
    x /= 10;
  } while (x > 0);
  return dp(n - 1, 0, 1, -1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long a, b;
  cin >> a >> b;

  memset(f, -1, sizeof(f));

//  cerr << sol(b) << " " << sol(a -1 ) << endl;

  cout << sol(b) - sol(a-1);

  return 0;
}
