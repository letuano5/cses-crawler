#include <bits/stdc++.h>
using namespace std;

bool dp[100005];
int n, s, a[1005];

int main(){
  cin >> n;
  dp[0] = 1;
  for(int i = 1; i <= n; i++) cin >> a[i], s += a[i];
  for(int i = 1; i <= n; i++)
    for(int j = s; j >= a[i]; j--) if(!dp[j] && dp[j - a[i]]) dp[j] = 1;
  vector <int> v;
  for(int i = 1; i <= s; i++) if(dp[i]) v.push_back(i);
  cout << v.size() << '\n';
  for(const int &i: v) cout << i << ' ';
}
