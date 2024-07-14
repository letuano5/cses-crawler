#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ull unsigned long long

int n, res, curr;
vector <pair <int, int> > v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.pb({x, 1}); // arrive
        v.pb({y, -1}); // leave
    }

    sort(v.begin(), v.end());

    for(const auto &c : v)
        curr += c.second, res = max(res, curr);

    cout << res;

    return 0;
}
