#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;
ll dp[150000];

ll PowMod(ll a, ll b, ll mod){
  if(!b) return 1;
  ll t = PowMod(a, b / 2, mod) % mod;
  if(b % 2) return t % mod * t % mod * a;
  return t % mod * t % mod;
}

int main(){
  ll n;
  cin >> n;
  ll sum = n * (n + 1) / 2;
  if(sum % 2) return !(cout << 0);
  sum /= 2;
  dp[0] = 1;
  for(int i = 1; i <= n; i++)
    for(ll j = sum; j >= i; j--) dp[j] += dp[j - i], dp[j] %= MOD;
//  cout << dp[sum] << "\n";
//  cout << PowMod(2, 3, 69696);
  cout << dp[sum] * PowMod(2, 1000000005, 1000000007) % MOD;
  return 0;
}
