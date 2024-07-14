#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int cnt(1),ma(1),len;
    len=s.length();
    for(int i = 0; i < len-1; i++){
        if(s[i]==s[i+1])
            cnt++;
        else{
            ma=max(cnt,ma);
            cnt=1;
        }
    }
    cout << max(cnt,ma);
    return 0;
}
