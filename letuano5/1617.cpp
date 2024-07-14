#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll mu(ll a, ll n)
{
    if(n == 0) return 1;
    ll temp = mu(a,n/2);
    temp = (temp*temp)%mod;
    if(n % 2 == 1) temp = (temp * a)%mod;
    return temp;
}
int main()
{
    long long n;
    cin >> n;
    cout << mu(2,n);
}
