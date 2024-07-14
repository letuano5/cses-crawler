#include<bits/stdc++.h>
using namespace std;

void debug_out() { cerr << '\n'; }
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
  cerr << " " << H;
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

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

const int N = 2e5 + 5;

int n, q;
int val[N];
int tin[N];
int tout[N];
int time_dfs;
int flatten_tree[N];
vector <int> g[N];

void dfs (int u, int par) {
  tin[u] = ++time_dfs;
  flatten_tree[time_dfs] = u;
  for (int v: g[u]) {
    if (v == par)
      continue;
    dfs(v, u);
  }
  tout[u] = time_dfs;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;

  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }

  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  FT <long long> ft(n); // f[i]: value from 1 -> i
  dfs(1, -1);

  for (int i = 1; i <= n; i++) {
    // nodes in subtree root i -> pass through i
    ft.upd(tin[i], val[i]);
    ft.upd(tout[i] + 1, -val[i]);
  }

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int s, x;
      cin >> s >> x;
      ft.upd(tin[s], x - val[s]);
      ft.upd(tout[s] + 1, val[s] - x);
      val[s] = x;
    }
    else {
      int s;
      cin >> s;
      cout << ft.get(tin[s]) << "\n";
    }
  }

  return 0;
}
