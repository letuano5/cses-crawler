#include <bits/stdc++.h>
using namespace std;
map <long long, bool>ok;
long long a[200005],s(0);
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        ok[a[i]]=true;
    }
    sort(a+1,a+1+n);
    for (int i = 1; i <= n; i++){
        if (ok[a[i]]){
            s++;
            ok[a[i]]=false;
        }
    }
    cout << s;
    return 0;
}
