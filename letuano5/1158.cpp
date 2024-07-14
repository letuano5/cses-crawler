#include <bits/stdc++.h>
using namespace std;

long long dp[100001];
int w[1001], v[1001];

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    cin >> w[i];
  for(int i = 1; i <= n; i++)
    cin >> v[i];
  for(int i = 1; i <= n; i++)
    for(int j = m; j >= w[i]; j--)
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
  cout << dp[m];
}