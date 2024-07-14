#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5050;

int n, m;
int x[N], w[N];
int xx[N], ww[N];
int s[N];
int s2[N];
int f[N][N];
int32_t idx[N];
int dp[N], ndp[N];

void solve (int L, int R, int optL, int optR) {
  if (L > R) {
    return;
  }

  int mid = (L + R) >> 1;
  int opt = -1;

  for (int i = optL; i <= min(mid - 1, optR); i++) {
    if (opt == -1) {
      opt = i;
    }
    else if (dp[opt] + f[opt + 1][mid] > dp[i] + f[i + 1][mid]) {
      opt = i;
    }
  }

  ndp[mid] = dp[opt] + f[opt + 1][mid];
  solve(L, mid - 1, optL, opt);
  solve(mid + 1, R, opt, optR);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;

  if (m >= n) {
    cout << 0;
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    cin >> ww[i];
    xx[i] = i;
    idx[i] = i;
  }

  sort(idx + 1, idx + n + 1, [&] (int i, int j) {return xx[i] < xx[j];});
  for (int i = 1; i <= n; i++) {
    x[i] = xx[idx[i]];
    w[i] = ww[idx[i]];
  }

  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + w[i];
    s2[i] = s2[i - 1] + w[i] * x[i];
  }

  memset(f, 0x3f, sizeof(f));
  memset(dp, 0x3f, sizeof(dp));
  memset(ndp, 0x3f, sizeof(ndp));

  auto cost = [&] (int i, int j, int k) -> int {
    // < x[k]
    int sum_left = (x[k] * (s[k - 1] - s[i - 1])) - (s2[k - 1] - s2[i - 1]);
    // > x[k]
    int sum_right = s2[j] - s2[k] - x[k] * (s[j] - s[k]);

    return sum_left + sum_right;
  };

  for (int i = 1; i <= n; i++) {
    int best_k = i;
    for (int j = i; j <= n; j++) {
      // move to k

      while (best_k + 1 <= j && cost(i, j, best_k) > cost(i, j, best_k + 1)) {
        ++best_k;
      }

      f[i][j] = cost(i, j, best_k);
    }
  }

  dp[0] = 0;

  for (int g = 1; g <= m; g++) {
    solve(1, n, 0, n);
    for (int i = 1; i <= n; i++) {
      dp[i] = ndp[i];
    }
  }

  cout << dp[n];
  return 0;
}
