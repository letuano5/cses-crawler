#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll a[50], S, cnt, mi(LLONG_MAX);
int x[50];
vector <ll> X;
int n, k;

void out1(){
    ll s = 0;
    for(int i = 1; i <= k; i++)
        if(x[i]) s += a[i];
    X.pb(s);
}

void Try(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if (i == k)
            out1();
        else
            Try(i + 1);
    }
}

void out2(){
    ll Y = 0;
    for(int i = k + 1; i <= n; i++)
        if (x[i]) Y += a[i];
    //x <= s/2 -y
    auto it = upper_bound(X.begin(), X.end(), S / 2 - Y);
    if (it == X.begin()) return;
    auto itt = *(--it);
    auto val = S - 2 * (itt + Y);
    if (mi > val){
        mi = val;
//        cnt = 1;
        cnt = upper_bound(X.begin(), X.end(), itt) - lower_bound(X.begin(), X.end(), itt);
    }
    else if (mi == val) cnt += upper_bound(X.begin(), X.end(), itt) - lower_bound(X.begin(), X.end(), itt);
}

void Try2(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if (i == n) out2();
        else Try2(i + 1);
    }
}

int main(){
    cin >> n;
    k = n / 2;
    if(n == 1){
        cin >> n;
        cout << n;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        S += a[i];
    }
    Try(1);
    sort(X.begin(), X.end());
//    k = n - k;
    Try2(k + 1);
    cout << mi; //<< ' ' << (!mi ? cnt / 2 : cnt);
}
