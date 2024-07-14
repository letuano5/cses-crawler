#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
const int MAX_BLOCK = 500;

int a[MAX_N];
long long s[MAX_BLOCK];

int main(){
  int n, q;
  cin >> n >> q;

  for(int i = 0; i < n; i++){
    cin >> a[i];
    s[i / MAX_BLOCK] += a[i];
  }

  while(q--){
    int query;
    cin >> query;

    if(query == 1){
      int id, val;
      cin >> id >> val;
      --id;
      s[id / MAX_BLOCK] += val - a[id];
      a[id] = val;
    }

    else{
      long long ans = 0;
      int l, r;
      cin >> l >> r;
      --l, --r;

      int blockL = l / MAX_BLOCK;
      int blockR = r / MAX_BLOCK;

      if(blockL == blockR){
        for(int i = l; i <= r; i++)
          ans += a[i];
        cout << ans << '\n';
        continue;
      }

      for(int i = l, endP = (blockL + 1) * MAX_BLOCK - 1; i <= endP; i++)
        ans += a[i];
      for(int i = blockL + 1; i <= blockR - 1; i++)
        ans += s[i];
      for(int i = blockR * MAX_BLOCK; i <= r; i++)
        ans += a[i];

      cout << ans << '\n';
    }
  }

  return 0;
}