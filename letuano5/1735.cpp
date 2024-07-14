#include<bits/stdc++.h>
using namespace std;

void debug_out() { cerr << '\n'; }
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
  cerr << " " << H;
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int N = 2e5 + 5;

#define int long long
int st[N << 2];
int lazy_add[N << 2];
int lazy_set[N << 2];

void push(int id, int l, int r){
  int &val_set = lazy_set[id];

  int mid = (l + r) >> 1;

  if(val_set){
    st[id << 1] = (mid - l + 1) * val_set;
    st[id << 1 | 1] = (r - mid) * val_set;
    lazy_add[id << 1] = lazy_add[id << 1 | 1] = 0;
    lazy_set[id << 1] = lazy_set[id << 1 | 1] = val_set;
    val_set = 0;
  }

  int &val_add = lazy_add[id];
  if(val_add){
    (st[id << 1] += (mid - l + 1) * val_add);
    (st[id << 1 | 1] += (r - mid) * val_add);
    (lazy_add[id << 1] += val_add);
    (lazy_add[id << 1 | 1] += val_add);
    val_add = 0;
  }
}

void update_add(int id, int l, int r, int u, int v, int val){
  if(v < l || r < u)
    return;
  if(u <= l && r <= v){
    (st[id] += (r - l + 1) * val);
    (lazy_add[id] += val);
    return;
  }
  push(id, l, r);
  int mid = (l + r) >> 1;
  update_add(id << 1, l, mid, u, v, val);
  update_add(id << 1 | 1, mid + 1, r, u, v, val);
  st[id] = (st[id << 1] + st[id << 1 | 1]);
}

void update_set(int id, int l, int r, int u, int v, int val){
  if(v < l || r < u)
    return;
  if(u <= l && r <= v){
    (st[id] = (r - l + 1) * val);
    lazy_set[id] = val;
    lazy_add[id] = 0;
    return;
  }
  push(id, l, r);
  int mid = (l + r) >> 1;
  update_set(id << 1, l, mid, u, v, val);
  update_set(id << 1 | 1, mid + 1, r, u, v, val);
  st[id] = (st[id << 1] + st[id << 1 | 1]);
}


int get(int id, int l, int r, int u, int v){
  if(v < l || r < u)
    return 0;
  if(u <= l && r <= v)
    return st[id];
  push(id, l, r);
  int mid = (l + r) >> 1;
  return (get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v));
}

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    update_set(1, 1, n, i, i, x);
  }

  while(m--){
    int type;
    cin >> type;

    if(type != 3){
      int l, r, x;
      cin >> l >> r >> x;
      if(type == 1)
        update_add(1, 1, n, l, r, x);
      else{
        update_set(1, 1, n, l, r, x);
      }
    }
    else{
      int l, r;
      cin >> l >> r;
      cout << get(1, 1, n, l, r) << '\n';
    }
  }

  return 0;
}
