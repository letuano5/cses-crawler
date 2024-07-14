#include <bits/stdc++.h>
using namespace std;

void debug_out() { cerr << '\n'; }
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
  cerr << " " << H;
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

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

  int size() {
    return val.size();
  }
};

template <class T>
struct FT {
  vector <T> ft;
  FT (int _n = 0) {
    ft.assign(_n + 5, 0);
  }
  void upd (int id, T val) {
    for (; id < (int)ft.size(); id += id & -id) ft[id] += val;
  }
  T get (int id) {
    T ans = 0;
    for (; id > 0; id -= id & -id) ans += ft[id];
    return ans;
  }
};

struct Range {
  int x, y, id;
  Range (int _x = 0, int _y = 0, int _i = 0) {
    x = _x;
    y = _y;
    id = _i;
  }

  bool operator < (const Range& that) const {
    if (x != that.x)
      return x > that.x;
    return y < that.y;
  }

  bool operator > (const Range& that) const {
    if (x != that.x)
      return x < that.x;
    return y > that.y;
  }

  friend istream& operator >> (istream& ist, Range& that) {
    ist >> that.x >> that.y;
    return ist;
  }
};

const int N = 2e5 + 5;

Range ranges[N];
FT <int> ft(2*N);
Compressor <int> cps;
int ans[N];
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ranges[i];
    ranges[i].id = i;
    cps.add(ranges[i].y);
  }

  cps.init();

  sort(ranges + 1, ranges + 1 + n);

  auto print = [&] () {
    for (int i = 1; i <= n; i++)
      debug(ranges[i].x, ranges[i].y, ranges[i].id);
  };

//  print();

  for (int i = 1; i <= n; i++) {
    int id = cps.idx(ranges[i].y);
    ans[ranges[i].id] = ft.get(id);
    ft.upd(id, 1);
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
    ans[i] = 0;
    ft.upd(cps.idx(ranges[i].y), -1);
  }

//  ft = FT <int> (N*2);
  sort(ranges + 1, ranges + 1 + n, greater <Range> ());

//  print();

  for (int i = 1; i <= n; i++) {
    int id = cps.idx(ranges[i].y);
    ans[ranges[i].id] = ft.get(cps.size()) - ft.get(id - 1);
    ft.upd(id, 1);
  }

  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";

  return 0;
}
