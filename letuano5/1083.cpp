#include <bits/stdc++.h>
using namespace std;
#define FORU(i,a,b) for (int i = a; i <= b; i++)
long long a[200005];
int n;
int main() {
    cin >> n;
    int tmp=n-1;
    FORU(i,1,tmp)
        cin >> a[i];
    sort(a+1,a+1+tmp);
    FORU(i,1,n)
        if(a[i]!=i){
            cout << i;
            break;
        }
    return 0;
}
