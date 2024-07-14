#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll res(0),t(0);
pair <ll,ll> dead[200005];
int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> dead[i].first >> dead[i].second;
    sort(dead,dead+n);
    for (int i = 0; i < n; i++){
        t+=dead[i].first;
        res+=dead[i].second-t;
    }
    cout<<res;
    return 0;
}
