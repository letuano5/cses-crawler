// a^b^c%mod

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod 1000000007

ll pw(ll a, ll n, ll p){
    if (n==0)
        return 1;
    ll t=pw(a,n/2,p);
    t=t*t%p;
    if (n%2==1)
        t=t*a%p;
    return t;
}

//ll pw(ll x, ll y, ll p){
//    ll res(1);
//    x=x%p;
//    while (y > 0){
//        if(y%2)
//            res=(res*x)%p;
//        y/=2;
//        x=(x*x)%p;
//    }
//    return res;
//}

ll calc(ll a, ll b, ll c){
    ll res,ans;
    res=pw(b,c,mod-1);
    ans=pw(a,res,mod);
    return ans;
}

int main(){
    int n;
    ll a,b,c;
    cin >> n;
    while(n--){
        cin >>a >> b >> c;
        cout << calc(a,b,c) << '\n';
    }
    return 0;
}
