#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int d[255];
ll ts,ms(1);

ll gt(ll n){
    if (n==0)
        return 1;
    ll p(1);
    for(ll i = 1; i <= n; i++)
        p=p%mod*i%mod;
    return p;
}

ll pw(ll a, ll n){
    if (n==0)
        return 1;
    ll tmp = pw(a,n/2);
    tmp=tmp*tmp%mod;
    if (n%2==1)
        tmp = (tmp*a)%mod;
    return tmp;
}

ll C(ll k, ll n){
    ll ts=gt(n);
    ll ms=gt(k)*gt(n-k)%mod;
    return (ts*pw(ms,mod-2))%mod;
}

int main(){
    int n,m;
    cin >> n >> m;
    cout << C(m,n+m-1);
    return 0;
}
