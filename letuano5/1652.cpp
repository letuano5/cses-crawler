#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

int cnt[1005][1005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c;
            cin >> c;
            cnt[i][j] = cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1] + (c == '*');
        }
    }

    int y, x, Y, X;
    while(q--){
        cin >> y >> x >> Y >> X;
		cout << (cnt[Y][X] - cnt[y - 1][X] - cnt[Y][x - 1] + cnt[y - 1][x - 1]) << '\n';
    }

    return 0;
}
