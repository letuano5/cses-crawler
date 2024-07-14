/// https://math.stackexchange.com/questions/3274520/two-knight-on-chessboard

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        ll a = 1LL * i * i * (i * i - 1) / 2;
        ll b = 2LL * (i - 2) * (2LL * (i - 4) + 6);
        cout << a - b << '\n';
    }

    return 0;
}
