// copied from https://discuss.codechef.com/t/bitmask-dp-note-cses-counting-tilings/92175

#include <bits/stdc++.h>
using namespace std;

#define getbit(x, i) ((x) >> (i) & 1)

const int N = 1e3 + 5;
const int M = 10;
const int MOD = 1e9 + 7;

int f[N][1 << M];
bool ok[1 << M][1 << M];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  // 0 : free, 1 : occupied by a block
  for (int cur_mask = 0; cur_mask < (1 << n); cur_mask++) {
    int rev = ((1 << n) - 1) ^ cur_mask;
    for (int nxt_mask = rev; nxt_mask >= 0; nxt_mask = (nxt_mask - 1) & rev) {
      bool cur = 1;
      for (int i = 0; i < n; i++) {
        if (getbit(cur_mask, i) && getbit(nxt_mask, i)) {
          cur = 0;
          break;
        }
        if (getbit(cur_mask, i) == 0 && getbit(nxt_mask, i) == 0) {
          if (i + 1 < n && getbit(cur_mask, i + 1) == 0 && getbit(nxt_mask, i + 1) == 0) {
            i++;
            continue;
          }
          cur = 0;
          break;
        }
      }
      ok[cur_mask][nxt_mask] = cur;
      if (nxt_mask == 0)
        break;
    }
  }

  f[0][0] = 1;

  for (int row = 0; row < m; row++) {
    for (int last_mask = 0; last_mask < (1 << n); last_mask++) {
      if (f[row][last_mask] == 0)
        continue;

      int rev = ((1 << n) - 1) ^ last_mask;

      for (int nxt_mask = rev; nxt_mask >= 0; nxt_mask = (nxt_mask - 1) & rev) {
        if (!ok[last_mask][nxt_mask]) {
          if (nxt_mask == 0) break;
          continue;
        }
        f[row + 1][nxt_mask] += f[row][last_mask];
        if (f[row + 1][nxt_mask] >= MOD)
          f[row + 1][nxt_mask] -= MOD;
        if (nxt_mask == 0) break;
      }
    }
  }

  cout << f[m][0];

//  for (int mask = 0; mask < (1 << n); mask++)
//    cerr << f[m][mask] << endl;
  return 0;
}
