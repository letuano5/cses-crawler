#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

int k, n;
ll x, tmp_S, res;
vector <ll> ok;
//map <ll, int> ok;
vector <ll> v;

void Try(int i){
    for(int j = 0; j <= 1; j++){
        tmp_S += j * v[i];
        if (i == k - 1){
            if(tmp_S <= x) ok.push_back(tmp_S);
        }
        else
            Try(i + 1);
        tmp_S -= j * v[i];
    }
}

void Try1(int i){
    for(int j = 0; j <= 1; j++){
        tmp_S += j * v[i];
        if (i == n - 1){
            res += upper_bound(ok.begin(), ok.end(), x - tmp_S) - lower_bound(ok.begin(), ok.end(), x - tmp_S);
            //if (ok.count(x - tmp_S)) res += ok[x - tmp_S];
        } else Try1(i + 1);
        tmp_S -= j * v[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    if (n == 1){
        cin >> n;
        cout << (x == n ? 1 : 0);
        return 0;
    }

    k = n / 2;

    for(int i = 0; i < n; i++){
        ll inp;
        cin >> inp;
        v.pb(inp);
    }

    Try(0);
    sort(ok.begin(), ok.end());
    tmp_S = 0;

    Try1(k);

    cout << res;

    return 0;
}
