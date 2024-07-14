#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x,ma(0),ans(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        ma=max(x,ma);
        ans+=ma-x;
    }
    cout << ans;
    return 0;
}
