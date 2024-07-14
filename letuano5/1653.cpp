#include <bits/stdc++.h>
using namespace std;

#define getbit(x, i) (((x) >> (i)) & 1LL)
#define onbit(x, i) ((x) | (1LL << (i)))
#define offbit(x, i) ((x) & (~(1LL << (i))))

pair <int, long long> dp[1 << 20]; // {x, y}: minimium num of elevators for state s (s[j] = 1 if j-th person is in elevator)
                                   //         and the weight of the last elevator

int n; long long w[21], x;

int main(){
  cin >> n >> x;
  for(int i = 0; i < n; i++) cin >> w[i];

  dp[0] = {1, 0};
  for(int mask = 1; mask < (1 << n); mask++){
    dp[mask] = {n + 1, 0};

    for(int i = 0; i < n; i++){
      if(!getbit(mask, i)) continue;

      pair <int, long long> state = dp[offbit(mask, i)];
      int c = state.first, ww = state.second;

      if(ww + w[i] <= x) ww += w[i];
      else c++, ww = w[i];

      dp[mask] = min(dp[mask], {c, ww});
    }
  }

  cout << dp[(1 << n) - 1].first;
}
