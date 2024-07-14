#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  int sum = 0, mn = 0, ans = -1e18;

  for(int x; n--; ){
    cin >> x;
    sum += x;
    ans = max(ans, sum - mn);
    mn = min(mn, sum);
  }

  cout << ans;
  return 0;
}
