#include <bits/stdc++.h>
using namespace std;

long long sum, a[200005];
int n, k;

bool ok(long long s){
  int res = 0;
  long long s_tmp = 0;
  for(int i = 1; i <= n; i++){
    if(a[i] > s) return 0;
    if(s_tmp + a[i] > s) res++, s_tmp = 0;
    s_tmp += a[i];
  }
  if(s_tmp) res++;
  return res <= k; // can divide to <= k groups ==> k groups
}

int main(){
  long long L = 0, R = 0, res;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i], R += a[i];
  while(L <= R){
    long long M = (L + R) / 2;
    if(ok(M)){
      res = M;
      R = M - 1;
    } else L = M + 1;
  }
  cout << res;
}
