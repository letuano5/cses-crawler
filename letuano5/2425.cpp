#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int mn[4 * N];
int mx[4 * N];
int lz[4 * N];

void push (int id) {
  for (int i = (id << 1); i <= (id << 1 | 1); i++) {
    mn[i] += lz[id];
    mx[i] += lz[id];
    lz[i] += lz[id];
  }
  lz[id] = 0;
}

void update (int id, int l, int r, int u, int v, int value) {
  if (v < l || r < u) {
    return;
  }
  if (u <= l && r <= v) {
    mn[id] += value;
    mx[id] += value;
    lz[id] += value;
    return;
  }

  push(id);
  int mid = (l + r) >> 1;
  update(id << 1, l, mid, u, v, value);
  update(id << 1 | 1, mid + 1, r, u, v, value);
  mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
  mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int s, c;
    cin >> s >> c;

    update(1, 1, n, 1, s, c == 1 ? 1 : -1);
    if (mn[1] >= 0) {
      cout << ">\n";
    }
    else if (mx[1] <= 0) {
      cout << "<\n";
    }
    else {
      cout << "?\n";
    }
  }

  return 0;
}
