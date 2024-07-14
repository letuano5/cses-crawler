#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ull unsigned long long
#define arr vector <string>

arr gray(int n){
    if (n <= 0)
        return {"0"};
    if (n == 1)
        return {"0", "1"};
    arr res, tmp = gray(n - 1);
    for(const string &s : tmp){
        res.pb("0" + s);
    }
    for(int i = tmp.size() - 1; i >= 0; i--)
        res.pb("1" + tmp[i]);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    arr ans = gray(n);

    for(const string &s : ans)
        cout << s << '\n';

    return 0;
}
