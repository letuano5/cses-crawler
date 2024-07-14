#include <bits/stdc++.h>
using namespace std;

int dp[501][501], a, b;

int main(){
  cin >> a >> b;
  for(int i = 1; i <= a; i++)
    for(int j = 1; j <= b; j++){
      if(i == j) dp[i][j] = 0;
      else{
        dp[i][j] = INT_MAX;
        for(int k = 1; k < i; k++) // cat chieu ngang
          dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
        for(int k = 1; k < j; k++) // cat chieu doc
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
      }
    }
  cout << dp[a][b];
  return 0;
}
