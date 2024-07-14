#include <bits/stdc++.h>
using namespace std;

void debug_out() { cerr << '\n'; }
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
  cerr << " " << H;
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int N = 2e5 + 5;
const int LG = __lg(N) + 5;

int n, q;
long long a[N];
int par[N][LG];
long long sum[N][LG];
long long pre[N];
long long ans[N];
vector <pair <int, int>> queries[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i],
    pre[i] = pre[i - 1] + a[i];

  pre[n + 1] = pre[n];
  a[n + 1] = 1e9;
  stack <int> st;
  st.push(n + 1);

  par[n + 1][0] = n + 1;

  for (int i = n; i >= 1; i--) {
    while (!st.empty() && a[st.top()] <= a[i])
      st.pop();

    par[i][0] = st.top();
    if (par[i][0] != n + 1)
      sum[i][0] = a[i] * (st.top() - i) - pre[st.top() - 1] + pre[i - 1];

    st.push(i);

  }

  for (int k = 1; k < LG; k++)
    for (int i = 1; i <= n + 1; i++) {
      par[i][k] = par[par[i][k - 1]][k - 1];
//      if (par[i][k] != n + 1)
      sum[i][k] = sum[i][k - 1] + sum[par[i][k - 1]][k - 1];
    }

//  cout << par[3][LG - 1] << endl;
//  return 0;

  while (q--) {
    int l, r; cin >> l >> r;
    long long cost = 0;

//    cout << par[l][LG - 1] << " ";

    for (int i = LG - 1; i >= 0; i--)
      if (par[l][i] <= r) {
//        debug(l, i, sum[l][i]);
//        cout << l << " " << i << " " << sum[l][i] << " ";
        cost += sum[l][i];
        l = par[l][i];
      }

//    debug(l, r, cost);
//    cout << l << " " << r << " " << cost << "--> " ;

    if (l <= r) {
      cost += a[l] * (r - l + 1) - pre[r] + pre[l - 1];
    }

    cout << cost << "\n";
  }

  return 0;
}
