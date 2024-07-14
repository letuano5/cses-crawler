#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll s(0),n,x,a,res(0);
map <ll,ll> ok;
int main(){
    cin >> n >> x;
    // for example, a[i]=x is also a subarray, and it has one element.
    ok[0]=1;
    for (int i = 0; i < n; i++){
        cin >> a;
        s+=a;
        res+=ok[s-x];
        ok[s]++;
    }
    cout << res;
    return 0;
}
