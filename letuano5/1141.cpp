#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
#define ll long long
#define FORU(i,a,b) for (int i = a; i < b; i++)
ll a[MAX];
map<ll,ll>ok;
int main(){
    int n,res(0);
    cin >> n;
    FORU(i,0,n)
        cin >> a[i];
    for (int i = 0, j = 0; i < n; i++){
        while (j < n && ok[a[j]]<1){
            ok[a[j]]++;
            j++;
        }
        res=max(j-i,res);
        ok[a[i]]--;
    }
    cout<<res;
    return 0;
}
