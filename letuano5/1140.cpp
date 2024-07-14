#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
template <class T>
struct Compressor {
  vector <T> val;

  void add (T x) {
    val.push_back(x);
  }

  void init() {
    sort(all(val));
    val.resize(unique(all(val)) - val.begin());
  }

  int idx(T x) {
    return lower_bound(all(val), x) - val.begin() + 1;
  }
};

const int N = 2e5 + 5;

int n;
int a[N], b[N], p[N];
vector <pair <int, int>> end_at[2 * N];
long long dp[2 * N];
Compressor <int> cps;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> p[i];
    cps.add(a[i]);
    cps.add(b[i]);
  }

  cps.init();

  for (int i = 1; i <= n; i++) {
    a[i] = cps.idx(a[i]);
    b[i] = cps.idx(b[i]);
    end_at[b[i]].emplace_back(a[i], p[i]);
  }

  n = cps.val.size();

  for (int r = 1; r <= n; r++) {
    dp[r] = dp[r - 1];
    for (auto [l, w] : end_at[r]) {
      dp[r] = max(dp[r], dp[l - 1] + w);
    }
  }

  cout << *max_element(dp + 1, dp + n + 1);

  return 0;
}
