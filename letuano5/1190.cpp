#include<bits/stdc++.h>
using namespace std;
 
#define int long long
const int INF = 1e18;
const int N = 2e5 + 5;
 
int a[N];
struct Node{
  int sum;
  int maxPrefix, maxSuffix;
  int ans;
 
  Node(){
    sum = 0;
    maxPrefix = maxSuffix = ans = -INF;
  }
 
  Node(int _sum, int _maxPrefix, int _maxSuffix, int _ans){
    sum = _sum;
    maxPrefix = _maxPrefix;
    maxSuffix = _maxSuffix;
    ans = _ans;
  }
} st[N << 2];
 
Node combine(Node x, Node y){
  Node res;
  res.sum = x.sum + y.sum;
  res.maxPrefix = max(x.maxPrefix, x.sum + y.maxPrefix);
  res.maxSuffix = max(y.maxSuffix, y.sum + x.maxSuffix);
  res.ans = max({res.maxPrefix, res.maxSuffix, x.ans, y.ans, x.maxSuffix + y.maxPrefix});
  return res;
}
 
void build(int id, int l, int r){
  if(l == r){
    st[id] = {a[l], a[l], a[l], a[l]};
    return;
  }
 
  int m = (l + r) >> 1;
  build(id << 1, l, m);
  build(id << 1 | 1, m + 1, r);
  st[id] = combine(st[id << 1], st[id << 1 | 1]);
}
 
void update(int id, int l, int r, int i, int val){
  if(i < l || r < i)
    return;
  if(l == r){
    st[id] = {val, val, val, val};
    return;
  }
  int m = (l + r) >> 1;
  update(id << 1, l, m, i, val);
  update(id << 1 | 1, m + 1, r, i, val);
  st[id] = combine(st[id << 1], st[id << 1 | 1]);
}
 
Node get(int id, int l, int r, int u, int v){
  if(v < l || r < u)
    return Node();
  if(u <= l && r <= v)
    return st[id];
  int m = (l + r) >> 1;
  return combine(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}
 
int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  int n, q;
  cin >> n >> q;
 
  for(int i = 1; i <= n; i++)
    cin >> a[i];
 
  build(1, 1, n);
 
  // int q;
  // cin >> q;
  while(q--){
    int x, y;
    cin >> x >> y;
    a[x] = y;
    update(1, 1, n, x, y);
    cout << max(0ll, get(1, 1, n, 1, n).ans) << '\n';
  }
  return 0;
}