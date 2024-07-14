#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n;
ll d, a[1000005], x, s, res;

void solve(){
    s = 0, res = 0;
    memset(a, 0, sizeof(a));
    a[0] = 1;
    cin >> n;
    d = n;
    for(int i = 0; i < n; i++){
        cin >> x;
        s = (s % d + x % d + d) % d;
        res += a[s];
        a[s]++;
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen("DIVSEQ.INP", "r"))
        freopen("DIVSEQ.INP", "r", stdin),
        freopen("DIVSEQ.OUT", "w", stdout);

    int T;
    for(T = 1; T--;)
        solve();

    return 0;
}
