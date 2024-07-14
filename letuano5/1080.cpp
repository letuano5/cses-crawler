#include <bits/stdc++.h>

using namespace std;

template <int MOD_>
struct modint {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

 private:
  using ll = long long;
  int v;
  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

 public:
  modint() : v(0) {}
  modint(ll v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend ostream& operator<<(ostream& out, const modint& n) { return out << int(n); }
  friend istream& operator>>(istream& in, modint& n) {
    ll v_;
    in >> v_;
    n = modint(v_);
    return in;
  }
  friend bool operator==(const modint& a, const modint& b) { return a.v == b.v; }
  friend bool operator!=(const modint& a, const modint& b) { return a.v != b.v; }
  modint inv() const {
    modint res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modint inv(const modint& m) { return m.inv(); }
  modint neg() const {
    modint res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend modint neg(const modint& m) { return m.neg(); }
  modint operator-() const { return neg(); }
  modint operator+() const { return modint(*this); }
  modint& operator++() {
    v++;
    if (v == MOD) v = 0;
    return *this;
  }
  modint& operator--() {
    if (v == 0) v = MOD;
    v--;
    return *this;
  }
  modint& operator+=(const modint& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modint& operator-=(const modint& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modint& operator*=(const modint& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modint& operator/=(const modint& o) { return *this *= o.inv(); }
  friend modint operator++(modint& a, int) {
    modint r = a;
    ++a;
    return r;
  }
  friend modint operator--(modint& a, int) {
    modint r = a;
    --a;
    return r;
  }
  friend modint operator+(const modint& a, const modint& b) { return modint(a) += b; }
  friend modint operator-(const modint& a, const modint& b) { return modint(a) -= b; }
  friend modint operator*(const modint& a, const modint& b) { return modint(a) *= b; }
  friend modint operator/(const modint& a, const modint& b) { return modint(a) /= b; }
};

const int MOD = 1e9 + 7;
using mint = modint<MOD>;

const int N = 505;

mint f[N][N];
bool cal[N][N];
mint C[N][N];

string s;
int n;

mint dp(int i, int j) {
  if (i > j) {
    return 1;
  }
  if ((j - i + 1) % 2) {
    return 0;
  }
  mint& ans = f[i][j];
  if (cal[i][j]) return ans;
  cal[i][j] = 1;
  ans = 0;
  for (int k = i + 1; k <= j; k += 2) {
    // delete (i, k)
    if (s[i] == s[k]) {
      // we have (j - i + 1) / 2 deletions
      // since we can delete each segment [i + 1, k - 1] and [k + 1, j] in any order, the answer must be multiplied with comb((j - i + 1) / 2, (k - i + 1) / 2))
      ans += dp(i + 1, k - 1) * dp(k + 1, j) * C[(j - i + 1) / 2][(k - i + 1) / 2];
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#define task "a"
  if (fopen(task ".inp", "r")) {
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
  }
  cin >> s;
  n = s.size();
  s = ' ' + s;
  C[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  cout << dp(1, n);
  return 0;
}