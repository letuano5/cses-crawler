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

template <class T>
struct FT {
  vector <T> ft;
  FT (int _n = 0) {
    ft.assign(_n + 5, 0);
  }
  void upd (int id, T val) {
    for (id += 2; id < (int)ft.size(); id += id & -id) ft[id] += val;
  }
  T get (int id) {
    T ans = 0;
    for (id += 2; id > 0; id -= id & -id) ans += ft[id];
    return ans;
  }
};

#define x1 __x1__
#define x2 __x2__
#define y1 __y1__
#define y2 __y2__
using ll = long long;
const int OPEN     = -1,
          VERTICAL = 1,
          CLOSE    = 0;
const int N = 1e5 + 5;

struct Point {
  int x, type, y1, y2;
  Point (int _x = 0, int _t = CLOSE, int y_left = -1, int y_right = -1) {
    x = _x; type = _t;
    y1 = y_left, y2 = y_right;
  }
  bool operator < (const Point& that) const {
    if (x != that.x) return x < that.x;
    return type < that.type;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  Compressor <int> cps;
  vector <Point> points;

  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (y1 > y2) swap(y1, y2);
    if (x1 > x2) swap(x1, x2);
    cps.add(y1);
    cps.add(y2);
    if (x1 == x2) {
      points.emplace_back(x1, VERTICAL, y1, y2);
    }
    else {
      points.emplace_back(x1, OPEN, y1, -1);
      points.emplace_back(x2 + 1, CLOSE, y1, -1);
    }
  }

  cps.init();

  sort(points.begin(), points.end());
  FT <int> ft(2*N);
  ll ans = 0;

  for (auto& p : points) {
    if (p.type == OPEN) {
      p.y1 = cps.idx(p.y1);
      ft.upd(p.y1, 1);
    }
    if (p.type == VERTICAL) {
      p.y2 = cps.idx(p.y2);
      p.y1 = cps.idx(p.y1);
      ans += ft.get(p.y2) - ft.get(p.y1 - 1);
    }
    if (p.type == CLOSE) {
      p.y1 = cps.idx(p.y1);
      ft.upd(p.y1, -1);
    }
  }

  cout << ans;
  return 0;
}

