#include <bits/stdc++.h>
using namespace std;

int n;
long long k[200001], t;

bool c(long long time){
  long long s = 0;
  for(int i = 1; i <= n; i++){
    s += time / k[i];
    if(s >= t) return 1;
  }

  return (s >= t);
}

int main(){
  cin >> n >> t;
  for(int i = 1; i <= n; i++) cin >> k[i];

  long long L = 0, R = 1e18, res = 0;

  while(L <= R){
    long long M = (L + R) / 2;
    if(c(M)) res = M, R = M - 1;
    else L = M + 1;
  }

  cout << res;
}
