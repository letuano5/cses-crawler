#include <bits/stdc++.h>
using namespace std;

long long dp[5005][5005], sum;
int n, a[5005];

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];

  for(int i = 1; i <= n; i++) dp[i][i] = a[i];
  for(int len = 2; len <= n; len++){
    for(int i = 1; i <= n - len + 1; i++){
      int j = i + len - 1;
      dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
    }
  }
  cout << (sum + dp[1][n]) / 2;
  return 0;
}
