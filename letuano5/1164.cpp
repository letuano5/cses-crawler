#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;

pair<int, int> a[N];
int b[N];

int main()
{
  int n;
  cin >> n;

  int nn = 0;
  for (int i = 1; i <= n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[++nn] = {x, i};
    a[++nn] = {y + 1, -i};
  }

  sort(a + 1, a + 1 + nn);

  vector<int> s;
  int cnt = 0, ans = 0;

  for (int i = 1; i <= nn; i++)
  {
    auto [u, v] = a[i];

    if (v < 0)
    {
      --cnt;
      s.push_back(b[-v]);
    }
    else
    {
      ++cnt;
      if(!s.empty())
        b[v] = s.back(),
        s.pop_back();
      else
        b[v] = cnt;
    }

    ans = max(ans, cnt);
  }

  cout << ans << '\n';
  for (int i = 1; i <= n; i++)
    cout << b[i] << " ";
  return 0;
}