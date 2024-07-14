#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector <int> a(n);

  for (int& i: a)
    cin >> i;

  sort(a.begin(), a.end());

  long long cur = 0;
  for (int i: a) {
    if (i > cur + 1) {
      break;
    }
    cur += i;
  }

  cout << cur + 1;
  return 0;
}
