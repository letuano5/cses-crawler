#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LG = 50;

template <typename T>
struct RMQ {
  vector <vector <T>> st;
  vector <T> a;
  int n;

  RMQ (int _n = 0) {
    n = _n;
    a.assign(n + 5, 0);
    st.assign(n + 5, vector <long long> (__lg(n+1) + 5, 0));
  }

  void ass (int id, int x) {
    a[id] = x;
  }

  T join (T a, T b) {
    return min(a, b);
  }

  void build() {
    for (int i = 1; i <= n; i++)
      st[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 1; i + (1 << j) - 1 <= n; i++)
        st[i][j] = join(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }

  T get (int L, int R) {
    if (L > R || R > n || n == 0)
      return 9e18;
    int j = __lg(R - L + 1);
    return join(st[L][j], st[R - (1 << j) + 1][j]);
  }
};

int n, q;
int a[N];
vector <int> idx[LG];
vector <long long> sum[LG];
RMQ <long long> rmq[LG];

void read_input() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
}

void precompute() {
  for (int k = 0; k < LG; k++) {
    idx[k] = {0};
    sum[k] = {0};
  }

  for (int k = 0; k < LG; k++) {
    for (int i = 1; i <= n; i++) {
      if (a[i] < (1ll << k) || a[i] >= (1ll << (k + 1)))
        continue;
      idx[k].emplace_back(i);
      sum[k].emplace_back(sum[k].back() + a[i]);
    }
    rmq[k] = RMQ <long long> (sum[k].size() - 1);
    for (int i = 1; i < sum[k].size(); i++) {
      rmq[k].ass(i, a[idx[k][i]]);
    }
    rmq[k].build();
  }
}

void solve() {
  while (q--) {
    int l, r;
    cin >> l >> r;

    long long mn = 9e18;
    long long s = 0;
    long long ans = -1;

    for (int k = 0; k < LG; k++) {
      int L = lower_bound(idx[k].begin(), idx[k].end(), l) - idx[k].begin();
      int R = upper_bound(idx[k].begin(), idx[k].end(), r) - idx[k].begin() - 1;

      if (s >= (1ll << (k + 1)) - 1) {
        ;
      }
      else { // 2^i - 1 <= s < 2^(i + 1)
        mn = rmq[k].get(L, R);
        if (mn > s + 1) {
          ans = s + 1;
          break;
        }
      }
      s += sum[k][R] - sum[k][L - 1];
    }

    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  read_input();
  precompute();
  solve();

  return 0;
}
