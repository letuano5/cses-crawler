#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll M = 1000000007;
map<ll, ll> F;

ll f(ll n) {
	if (F.count(n))
        return F[n];
	ll k=n/2;
	if (n%2==0) {
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else {
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}

int main(){
	ll n;
	F[0]=F[1]=1;
	cin >> n;
	cout << (n==0?0:f(n-1));
	return 0;
}
