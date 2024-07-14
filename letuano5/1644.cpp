#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, L, R;
ll best = -9e18;
ll sum[N];
deque <int> dq;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

//  freopen("SUMSEQ.INP", "r", stdin);
//  freopen("SUMSEQ.OUT", "w", stdout);

  cin >> n >> L >> R;
  for (int i = 1; i <= n; i++)
    cin >> sum[i],
    sum[i] += sum[i - 1];

  for (int i = L; i <= n; i++) {
    while (!dq.empty() && sum[i - L] <= sum[dq.back()])
      dq.pop_back();
    dq.push_back(i - L);
    while (!dq.empty() && dq.front() < i - R)
      dq.pop_front();
    best = max(best, sum[i] - sum[dq.front()]);
  }

  cout << best;

  return 0;
}
