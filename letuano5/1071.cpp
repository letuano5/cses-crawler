//cre GHTH
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    unsigned long long y,x;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> x >> y;
        if (x > y){
            if(x%2==0)
                cout << x*x-y+1;
            else
                cout << (x - 1)*(x-1)+y;
        }
        else{
            if (y%2==0)
                cout<<(y-1)*(y-1)+x;
            else
                cout<<y*y-x+1;
        }
        if (i < t)
            cout << '\n';
    }
    return 0;
}
