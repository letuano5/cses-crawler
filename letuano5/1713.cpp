#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int num(int x){
    if(x==1)
        return 1;
    int res(0);
    for (int i = 1; i <= sqrt(x); i++){
        if(x%i==0){
            res++;
            if(x/i!=i)
                res++;
        }
    }
    return res;
}

int main(){
    int n,cnt(0),x;
    cin >> n;
    while(n--){
        cin >> x;
        cout << num(x) << '\n';
    }
}
