#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
#define inf 10000007
int n,x,coin[250],value[MAX];

int main(){
    int n,x;
    cin >> n >> x;
    for (int i = 0 ; i< n; i++)
        cin >> coin[i];
    value[0]=0;
    for (int i = 1; i <= x; i++){
        value[i]=inf;
        for (int j = 0; j < n; j++)
            if(i - coin[j] >= 0)
                value[i]=min(value[i],value[i-coin[j]]+1);
    }
    cout << (value[x]==inf?-1:value[x]);
    return 0;
}
