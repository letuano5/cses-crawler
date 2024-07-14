#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
const int MAX_VAL = 2e5 + 5;
const int BLOCK_SIZE = 200;

struct Query {
  int L, R, id;

  bool operator < (const Query &q) const {
    if(L / BLOCK_SIZE != q.L / BLOCK_SIZE)
      return L < q.L;
    return (L / BLOCK_SIZE & 1) ? R < q.R : R > q.R;
  }
} Q[MAX_N];

int cnt[MAX_VAL];
int a[MAX_N];
int b[MAX_N];
int ans[MAX_N];
int curCnt;

inline void Add(const int &x){
  if(cnt[a[x]] == 0)
    ++curCnt;
  ++cnt[a[x]];
}

inline void Remove(const int &x){
  --cnt[a[x]];
  if(cnt[a[x]] == 0)
    --curCnt;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;

  for(int i = 1; i <= n; i++)
    cin >> a[i],
    b[i] = a[i];

  sort(b + 1, b + 1 + n);

  for(int i = 1; i <= n; i++)
    a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;

  // int q;
  // cin >> q;

  for(int i = 1; i <= q; i++)
    cin >> Q[i].L >> Q[i].R,
    Q[i].id = i;

  sort(Q + 1, Q + 1 + q);

  int curL = 1, curR = 0;
  for(int i = 1; i <= q; i++){
    while(curL < Q[i].L)
      Remove(curL++);
    while(curL > Q[i].L)
      Add(--curL);
    while(curR < Q[i].R)
      Add(++curR);
    while(curR > Q[i].R)
      Remove(curR--);

    ans[Q[i].id] = curCnt;
  }

  for(int i = 1; i <= q; i++)
    cout << ans[i] << "\n";

  return 0;
}