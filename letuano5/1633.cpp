#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
#define m 1000000007
long long F[MAX];
int n;
int main(){
    cin >> n;
    F[0]=1;
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= 6; j++){
            F[i+j]+=F[i];
            F[i+j]%=m;
        }
    }
    cout<<F[n];
    return 0;
}
