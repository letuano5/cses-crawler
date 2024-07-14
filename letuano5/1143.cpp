#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 5;

int a[N];
int st[4 * N];

void build(int id, int l, int r){
  if(l == r){
    st[id] = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(id * 2, l, m);
  build(id * 2 + 1, m + 1, r);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int i, int val){
  if(i < l || r < i)
    return;
  if(l == r){
    st[id] = val;
    return;
  }
  int m = (l + r) / 2;
  update(id * 2, l, m, i, val);
  update(id * 2 + 1, m + 1, r, i, val);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

// find minimum i: a[i] >= k
int binarySearch(int id, int l, int r, int k){
  if(st[id] < k)
    return -1;
  if(l == r)
    return l;
  int m = (l + r) / 2;

  if(st[id * 2] >= k)
    return binarySearch(id * 2, l, m, k);
  return binarySearch(id * 2 + 1, m + 1, r, k);
}

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  build(1, 1, n);

  while(m--){
    int x;
    cin >> x;

    int pos = binarySearch(1, 1, n, x);
    if(pos == -1){
      cout << 0 << ' ';
      continue;
    }

    cout << pos << ' ';

    if(a[pos] == x)
      a[pos] = -1e18;
    else
      a[pos] -= x;
    update(1, 1, n, pos, a[pos]);
  }

  return 0;
}