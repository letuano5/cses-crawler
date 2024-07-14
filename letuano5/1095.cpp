#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll mu(ll a, ll n)
{
    if(n==0) return 1;
    ll tam = mu(a,n/2);
    tam = (tam*tam)%mod;
    if(n%2==1) tam = (tam*a)%mod;
    return tam;
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        ll a,n;
        cin>>a>>n;
        cout<<mu(a,n)<<'\n';
    }
}
