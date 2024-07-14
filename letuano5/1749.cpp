#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 5;

int st[4 * N];
int a[N];

void build(int id, int l, int r){
  if(l == r){
    st[id] = 1;
    return;
  }

  int m = (l + r) / 2;
  build(id * 2, l, m);
  build(id * 2 + 1, m + 1, r);

  st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(int id, int l, int r, int i){
  if(r < i || i < l)
    return;
  if(l == r){
    st[id]--;
    return;
  }

  int m = (l + r) / 2;
  update(id * 2, l, m, i);
  update(id * 2 + 1, m + 1, r, i);
  st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v){
  if(v < l || r < u)
    return 0;
  if(u <= l && r <= v)
    return st[id];
  int m = (l + r) / 2;
  return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
}

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  build(1, 1, n);

  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;

    int L = 1, R = n, ans = -1;
    while(L <= R){
      int M = (L + R) / 2;
      if(get(1, 1, n, 1, M) >= x)
        ans = M,
        R = M - 1;
      else
        L = M + 1;
    }
    cout << a[ans] << " ";
    if(ans != -1) update(1, 1, n, ans);
  }

  return 0;
}
