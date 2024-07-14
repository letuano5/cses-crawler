/** LTo5 **/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
const ll mod = 1e9 + 7;

int cnt[1001][1001];
int main(){
    fast;
    int n; char c;
    cin >> n;
    cnt[0][0] = 1;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> c;
            if (c == '*')
                cnt[i][j] = 0;
//            else if (!(i + j))
//                cnt[i][j] = 1;
            else{
                cnt[i][j] += (i ? cnt[i - 1][j] : 0) + (j ? cnt[i][j - 1] : 0);
                cnt[i][j] %= mod;
            }
        }
    }
    cout << cnt[--n][n];
	return 0;
}
