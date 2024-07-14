#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int cot[30], cc[30], cp[30], n = 8, cnt;
char a[10][10];

void Try(int i){
    for(int j = 1; j <= n; j++){
        if (a[i][j] == '.' && !cot[j] && !cc[i - j] && !cp[i + j]){
            cot[j] = cc[i - j] = cp[i + j] = 1;
            if (i == n)
                cnt++;
            else
                Try(i + 1);
            cot[j] = cc[i - j] = cp[i + j] = 0;
        }
    }
}

int main(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    Try(1);
    cout<<cnt;
    return 0;
}
