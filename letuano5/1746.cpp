#include <bits/stdc++.h>
using namespace std;

long long dp[2][105];
int n, m, x;
const int MOD = 1e9 + 7;
bool k;

int main(){
  cin >> n >> m >> x;
  if(!x) for(int i = 1; i <= m; i++) dp[k][i] = 1;
  else dp[k][x] = 1;

  for(int i = 1; i < n; i++){
    cin >> x;
    k = i % 2;
    if(!x) for(int j = 1; j <= m; j++){
      dp[k][j] = dp[1 - k][j - 1] + dp[1 - k][j];
      if(j + 1 <= m) dp[k][j] += dp[1 - k][j + 1];
      dp[k][j] %= MOD;
    }
    else {
      for(int j = 1; j <= m; j++) if(j != x) dp[k][j] = 0;
      dp[k][x] = dp[1 - k][x - 1] + dp[1 - k][x];
      if(x + 1 <= m) dp[k][x] += dp[1 - k][x + 1];
      dp[k][x] %= MOD;
    }
  }

  long long res = 0;
  for(int i = 1; i <= m; i++) res += dp[k][i], res %= MOD;
  cout << res;
  return 0;
}
