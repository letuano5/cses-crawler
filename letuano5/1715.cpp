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

int main(){
    string s;
    cin >> s;
    int len=s.length();
    for (int i = 0; i <len; i++){
        d[s[i]]++;
    }
    for (int i = 0; i < 255; i++){
        if (d[i]>0)
            ms=ms%mod*gt(d[i])%mod;
    }
    ts=gt(len);
    cout << (ts*pw(ms,mod-2))%mod;
    return 0;
}
