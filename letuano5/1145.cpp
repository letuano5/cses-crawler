#include <bits/stdc++.h>
using namespace std;

multiset <int> s;
int n, x;

int main(){
  for(cin >> n; n--; ){
    cin >> x;
    auto it = s.lower_bound(x);
    if(it != s.end()) s.erase(it);
    s.insert(x);
  }
  cout << s.size();
}
