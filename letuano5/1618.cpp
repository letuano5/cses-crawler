#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,k(5),res(0);
    cin >> n;
    for(;n/k>0;n/=k){
        res+=n/k;
    }
    cout<<res;
}
