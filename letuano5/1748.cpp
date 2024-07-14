#include<bits/stdc++.h>
using namespace std;

void debug_out() { cerr << '\n'; }
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
  cerr << " " << H;
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

void add(int& a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}

struct BIT {
  typedef int T;
  T func (T a, T b) {
    add(a, b);
    return a;
  }

  vector <T> fen;
  int n = 0;
  T unit;

  BIT (int _n = 0, T _unit = 0) {
    n = _n;
    unit = _unit;
    fen.assign(n + 5, unit);
  }

  void update_pref (int idx, T val) {
    assert (idx >= 1 && idx <= n);
    for (; idx <= n; idx += idx & -idx) {
      fen[idx] = func(fen[idx], val);
    }
  }

  T get_pref (int idx) {
    assert (idx >= 1 && idx <= n);
    T ans = unit;
    for (; idx > 0; idx -= idx & -idx) {
      ans = func(ans, fen[idx]);
    }
    return ans;
  }

  void update_suff (int idx, T val) {
    assert (idx >= 1 && idx <= n);
    for (; idx > 0; idx -= idx & -idx)
      fen[idx] = func(fen[idx], val);
  }

  T get_suff (int idx) {
    assert (idx >= 1 && idx <= n);
    T ans = unit;
    for (; idx <= n; idx += idx & -idx) {
      ans = func(ans, fen[idx]);
    }
    return ans;
  }
};

#define all(x) (x).begin(), (x).end()
template <class T>
struct Compressor {
  vector <T> val;

  void add (int x) {
    val.push_back(x);
  }

  void init() {
    sort(all(val));
    val.resize(unique(all(val)) - val.begin());
  }

  int idx(int x) {
    return lower_bound(all(val), x) - val.begin() + 1;
  }
};

int a[N];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  Compressor <int> cps;
  BIT ft(n + 5);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cps.add(a[i]);
  }

  cps.init();

  int ans = 0;

  for (int i = 1; i <= n; i++) {
    int cur_idx = cps.idx(a[i]) + 1;
    int cur_dp = ft.get_pref(cur_idx - 1);
    add(cur_dp, 1);
    ft.update_pref(cur_idx, cur_dp);
    add(ans, cur_dp);
  }

  cout << ans;
  return 0;
}
