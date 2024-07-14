#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll x;
pair <ll,int> a[20005];
int main(){
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second=i;
    }
    sort(a,a+n);
    for (int i = 0; i < n; i++){
        ll x2=x-a[i].first;
        for (int j = i + 1, k = n - 1; j < k; j++){
            while (j<k&&a[j].first+a[k].first>x2)
                k--;
            if (j < k && a[j].first+a[k].first==x2){
                cout << a[i].second+1 << ' ' << a[j].second+1 << ' ' << a[k].second+1;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
