#include <bits/stdc++.h>
using namespace std;

int k, n, a[200001];
long long res;
map <int, int> cnt;

int main(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i];

  int dis = 0;
  for(int i = 1, j = 1; i <= n; i++){
    while(j <= n && dis + (cnt[a[j]] == 0) <= k) cnt[a[j]]++, dis += (cnt[a[j++]] == 1);
    res += j - i;
    dis -= (cnt[a[i]] == 1);
    cnt[a[i]]--;
  }

  cout << res;

  return 0;
}
