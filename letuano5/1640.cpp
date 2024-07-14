#include <bits/stdc++.h>
using namespace std;
#define ll long long

map <ll, int> ok;
ll x, a[200005];
int n;

int main(){
    cin >> n >> x;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ok[a[i]]=i;
    }

    for (int i = 1; i <= n; i++){
        if(ok.count(x - a[i]) && ok[x - a[i]] != i){
            cout << i << ' ' << ok[x - a[i]];
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
