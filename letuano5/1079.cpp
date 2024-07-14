#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(v) (int)(v).size()

ll fact[1000005];
const ll m = 1000000007;

ll pw (ll a, ll y){
    if (y == 0)
        return 1;
    ll t = pw(a, y/2) % m;
    t = t % m * t % m;
    if (y % 2)
        t = t % m * a % m;
    return t;
}

ll C(ll k, ll n){
    ll t1 = fact[n] % m;
    ll t2 = fact[k] % m * fact[n - k] % m;
    return t1 % m * pw(t2, m - 2) % m;
}


int main(){
    ll a, b, n = 1e6;
    fact[0] = 1;
    for(ll i = 1; i <= n; i++){
        fact[i] = fact[i - 1] % m * i % m;
    }
	for(cin >> n; n--; ){
		cin >> a >> b;
		cout << C(b, a) << '\n';
	}
    return 0;
}
