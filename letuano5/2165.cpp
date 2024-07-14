#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

void Move(int n, int x, int tmp, int y) {
  if (n == 1) {
    v.push_back({x, y});
    return;
  }
  Move(n - 1, x, y, tmp);
  Move(1, x, tmp, y);
  Move(n - 1, tmp, x, y);
}

int main() {
  int n;
  cin >> n;
  Move(n, 1, 2, 3);
  cout << v.size() << "\n";
  for (auto i : v) cout << i.first << " " << i.second << '\n';
  return 0;
}
