#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
#define ll long long
#define FORU(i,a,b) for (int i = a; i < b; i++)
ll a[MAX],b[MAX];
int main(){
    int n,m,k,res(0);
    cin >> n >> m >> k;
    FORU(i,0,n)
        cin >> a[i];
    FORU(i,0,m)
        cin >> b[i];
    sort(a,a+n);
    sort(b,b+m);
    int i=0,j=0;
    while (i < n && j < m){
        if (abs(a[i]-b[j])<=k){
            res++;
            i++;
            j++;
        }
        else if(a[i]-b[j]>k)
            j++;
        else
            i++;
    }
    cout<<res;
    return 0;
}
