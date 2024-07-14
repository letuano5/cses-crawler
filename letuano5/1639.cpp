#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[5005][5005];

int main(){
  cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
//  s1 = ' ' + s1, s2 = ' ' + s2;
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= m; j++){
      if(!i) dp[i][j] = j;
      else if(!j) dp[i][j] = i;
      else if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
        //add <=> remove
      else dp[i][j] = 1 + min({dp[i][j - 1],      // del s2[j]
                               dp[i - 1][j],      // del s1[i]
                               dp[i - 1][j - 1]});// replace s1[i]=s2[j]
    }

  cout << dp[n][m];
}
