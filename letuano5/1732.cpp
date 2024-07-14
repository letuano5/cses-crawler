#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
const int base = 31;
const long long mod = 1e9 + 7;

long long POW[MAX], hashS[MAX];
string s;

long long getHashT(int i,int j) {
  return (hashS[j] - hashS[i - 1] * POW[j - i + 1] + mod * mod) % mod;
}

int main(){
  cin >> s;
  int n = s.size();
  s = ' ' + s;

  POW[0] = 1;
  for(int i = 1; i <= n; i++) POW[i] = (POW[i - 1] * base) % mod;
  for(int i = 1; i <= n; i++) hashS[i] = (hashS[i - 1] * base + s[i] - 'a' + 1) % mod;

  for(int i = 1; i < n; i++)
    if(getHashT(1, i) == getHashT(n - i + 1, n)) cout << i << ' ';
  return 0;
}
