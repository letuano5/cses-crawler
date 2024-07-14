#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int BASE = 311;
const int64_t MOD = 1e9 + 9277;

int n, res;
string s;
int64_t power[N];
int64_t hash_s[N];
int64_t rev_hash_s[N];

int64_t get_hash(int L, int R, int64_t *H) {
  return (H[R] - H[L - 1] * power[R - L + 1] + MOD * MOD) % MOD;
}

bool is_palin(int L, int R) {
  if (L < 1 || R > n)
    return false;

  int L_rev = n - R + 1, R_rev = n - L + 1;
  return (get_hash(L, R, hash_s) == get_hash(L_rev, R_rev, rev_hash_s));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  n = s.size();

  s = ' ' + s;

  power[0] = 1;
  for (int i = 1; i <= n; i++) {
    power[i] = power[i - 1] * BASE % MOD;
    hash_s[i] = (hash_s[i - 1] * BASE + s[i] - 'a' + 1) % MOD;
    rev_hash_s[i] = (rev_hash_s[i - 1] * BASE + s[n - i + 1] - 'a' + 1) % MOD;
  }

  // i is center
  int best_o = 0;
  int best_e = 0;
  int ans = 1;
  int best_i = 1, best_j = 1;

  for (int i = 1; i <= n; i++) {
    while (is_palin(i - (best_o + 1), i + best_o + 1)) {
      ++best_o;
      if (ans < best_o * 2 + 1) {
        ans = best_o * 2 + 1;
        best_i = i - best_o;
        best_j = i + best_o;
      }
    }
    while (is_palin(i - best_e, i + best_e + 1)) {
      ++best_e;
      if (ans < best_e * 2) {
        ans = best_e * 2;
        best_i = i - best_e + 1;
        best_j = i + best_e;
      }
    }
  }

  cout << s.substr(best_i, best_j - best_i + 1);

  return 0;
}

// O(n)