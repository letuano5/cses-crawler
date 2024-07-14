#include <bits/stdc++.h>
#define ll long long
ll MAX = 1e18;
#define pb push_back
using namespace std;

ll res;
ll n;
int k, x[25];
vector <ll> p;

/// avoid overflow
ll mul(ll x, ll y){
    if (!y) return y;
    if (y == 1) return x;

    ll t = mul(x, y / 2);

    /// overflow case
    if (t == -1) return -1;
    return (t * 2 + (x * (y % 2)) <= MAX ? t * 2 + (x * (y % 2)) : -1);
}

void prod(){
    vector <ll> t;
    ll M = 1;

    for(int i = 0; i < k; i++)
        if (x[i]) t.pb(p[i]);

    if (t.empty()) return;
    for(ll i : t){
//        if (M > n / i) return;
//        M *= i;
        M = mul(M, i);
        if (M == -1) return;
    }

    if (t.size() % 2) res += n / M;
    else res -= n / M;
}

void Try(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if (i == k - 1) prod();
        else Try(i + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    p.resize(k);
    for(ll &i : p) cin >> i;

    Try(0);

    cout << res;

    return 0;
}
