#include <bits/stdc++.h>
using namespace std;
long long a[200005],x,ans(0);
int n;

int main(){
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n,greater<long long>());
    for(int i = 0,j=n-1;i<n,i<=j;i++){
        if (a[i]+a[j]<=x&&i!=j)
            j--;
        ans++;
    }
    cout<<ans;
    return 0;
}
