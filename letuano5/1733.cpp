#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int BASE = 31;
const long long MOD = 1e9 + 7;

long long hashT[N], POW[N];

long long getHash(int L, int R){
  return (hashT[R] - hashT[L - 1] * POW[R - L + 1] + MOD * MOD) % MOD;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

//  freopen("_inp.inp", "r", stdin);

  string s;
  cin >> s;

  int n = s.size();

  s = ' ' + s;

  POW[0] = 1;
  for(int i = 1; i <= n; i++)
    POW[i] = POW[i - 1] * BASE % MOD,
    hashT[i] = (hashT[i - 1] * BASE + s[i] - 'A' + 1) % MOD;

  for(int i = 1; i <= n; i++){
    bool can = true;

    int curLen = i;

    long long curHash = getHash(1, i);

    for(int j = i + 1; j + i - 1 <= n; j += i)
      if(getHash(j, j + i - 1) != curHash){
        can = false;
        break;
      }

    if(!can)
      continue;

    int remain = n - n / i * i;
    if(getHash(1, remain) != getHash(n - remain + 1, n))
      continue;

    cout << i << ' ';
  }

  return 0;
}
