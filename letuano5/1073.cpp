/** LTo5 **/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);


int main(){
	fast;
    int n, x;
    multiset <int> blocks;
    for (cin >> n; n--; ){
        cin >> x;
        auto it = blocks.upper_bound(x);
        if(it != blocks.end())
            blocks.erase(it);
        blocks.insert(x);
    }
    cout << blocks.size();
	return 0;
}
