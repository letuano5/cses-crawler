#include<bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;

bitset<30> bs[N];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;

  for(int i = 1; i <= n; i++){
    string s;
    cin >> s;

    for(int j = 0; j < k; j++)
      bs[i][j] = s[j] - '0';
  }

  int res = 1e9;
  for(int i = 1; i <= n; i++)
    for(int j = i + 1; j <= n; j++)
      res = min(res, (int)((bs[i] ^ bs[j]).count()));

  cout << res;

  return 0;
}
