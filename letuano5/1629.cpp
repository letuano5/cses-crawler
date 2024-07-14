#include <bits/stdc++.h>
using namespace std;

pair <long long, long long> a[200005];

bool cmp(const pair <long long, long long> &aa, const pair <long long, long long> &bb){
  return aa.second < bb.second;
}

int main(){
  int n, last = -1, cnt = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  sort(a + 1, a + 1 + n, cmp);
  for(int i = 1; i <= n; i++){
    if(a[i].first >= last)
      cnt++, last = a[i].second;
  }
  cout << cnt;
}
