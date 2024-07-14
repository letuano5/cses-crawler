#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int a[4005];
int b[4005];
int A[4005], B[4005];
int ans[4005][4005];
queue<pair<int, int>> q[4005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
#define task "a"
#else
#define task ""
#endif
  if (fopen(task ".inp", "r")) {
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    A[i] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    B[i] = b[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      q[b[j]].emplace(i, j);
    }
  }
  for (int i = n; i >= 0; i--) {
    while (!q[i].empty()) {
      auto [u, v] = q[i].front();
      q[i].pop();
      // debug(i, u, v);
      if (b[v] != i) {
        q[b[v]].emplace(u, v);
        continue;
      }
      if (a[u] && b[v]) {
        a[u]--;
        b[v]--;
        ans[u][v] = 1;
      } else {
        ans[u][v] = 0;
      }
    }
  }
  bool fail = 0;
  for (int i = 1; i <= n; i++) {
    int sumRow = 0;
    for (int j = 1; j <= n; j++) sumRow += ans[i][j];
    if (sumRow != A[i]) {
      fail = 1;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    int sumCol = 0;
    for (int j = 1; j <= n; j++) sumCol += ans[j][i];
    if (sumCol != B[i]) {
      fail = 1;
      break;
    }
  }
  if (fail) {
    cout << -1 << "\n";
  } else {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << (ans[i][j] ? 'X' : '.');
      }
      cout << "\n";
    }
  }
  return 0;
}