#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt(0);
    cin >> n;
    string s=to_string(n);
    while (n > 0){
        sort(s.begin(),s.end(),greater<char>());
        int tmp = s[0]-'0';
        n-=tmp;
        s=to_string(n);
        cnt++;
    }
    cout<<cnt;
    return 0;
}
