#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_VAL = 1e6 + 5;

int dp[2][MAX_VAL];

int main(){
  dp[0][0] = 1;

  int n, x;
  cin >> n >> x;

  for(int i = 1; i <= n; i++){
    int c;
    cin >> c;

    for(int j = 0; j <= x; j++){
      int prv = 1 - i % 2;
      int cur = i % 2;

      dp[cur][j] = dp[prv][j];
      if(j >= c)
        dp[cur][j] += dp[cur][j - c];
      if(dp[cur][j] >= MOD)
        dp[cur][j] -= MOD;
    }
  }

  cout << dp[n % 2][x];
  return 0;
}
