#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

const ll mod = 1e9 + 7;

ll pw(ll a, ll n){
    if (n==0)
        return 1;
    ll tmp = pw(a,n/2) % mod;
    tmp=tmp%mod*tmp%mod;
    if (n%2==1)
        tmp = (tmp*a)%mod;
    return tmp;
}

int main(){
//    fact[0] = 1;
    ll n;
    cin >> n;
    if (n%2) return !(cout << 0);
    n /= 2;
    //fact[n/2]
    //  n/2+2...2n
    ll t = 1, m = 1;
    for(int i = 1; i <= n; i++)
        m = (m % mod * i % mod) % mod;
    for(int i = n + 2; i <= 2 * n; i++)
        t = (t % mod * i % mod) % mod;
    cout << (t % mod * pw(m, mod - 2) % mod) % mod;
    return 0;
}
