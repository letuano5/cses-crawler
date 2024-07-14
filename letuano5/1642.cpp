/** LTo5 **/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

bool isDistinct(pii p, int x, int y){
    return (p.first != x && p.first != y && p.second != x && p.second != y);
}


int main(){
	fast;
    vector <int> v;
    int n, x, t; cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> t;
        v.pb(t);
    }
    map <int, pii > seen;
    for(int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            seen[v[i] + v[j]] = {i, j};
        }
    }
    for(int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (seen.count(x - v[i] - v[j])){
                pii p = seen[x - v[i] - v[j]];
                if(isDistinct(p, i, j)){
                    cout << i + 1 << ' ' << j + 1 << ' ' << p.first + 1 << ' ' << p.second + 1;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
	return 0;
}
