#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

bool res[N], ans[N];

struct range {
  int x, y, pos;
} ranges[N];

bool cmp1(const range &a, const range &b){
  if(a.x != b.x) return a.x > b.x;
  return a.y < b.y;
}

bool cmp2(const range &a, const range &b){
  if(a.x != b.x) return a.x < b.x;
  return a.y > b.y;
}

int main(){
  int n;
  cin >> n;

  for(int i = 1; i <= n; i++)
    cin >> ranges[i].x >> ranges[i].y,
    ranges[i].pos = i;

  sort(ranges + 1, ranges + 1 + n, cmp1);

  set<int> s;
  for(int i = 1; i <= n; i++){
    auto [x, y, pos] = ranges[i];

    //<=y
    auto it = s.upper_bound(y);
    res[pos] = (it != s.begin());

    s.insert(y);
  }

  s.clear();
  sort(ranges + 1, ranges + 1 + n, cmp2);

  for(int i = 1; i <= n; i++){
    auto [x, y, pos] = ranges[i];

    auto it = s.lower_bound(y);
    ans[pos] = (it != s.end());

    s.insert(y);
  }

  for(int i = 1; i <= n; i++)
    cout << res[i] << ' ';
  cout << '\n';
  for(int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
}
