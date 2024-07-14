#include <bits/stdc++.h>
using namespace std;
int n,q;
long long a[200005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }

    int x,y;
    while (q--){
        cin >> x >> y;
        if (x==1)
            cout << a[y] << '\n';
        else
            cout << a[y]-a[x-1] << '\n';
    }
    return 0;
}
