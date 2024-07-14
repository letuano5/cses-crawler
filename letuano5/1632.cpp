#include <bits/stdc++.h>
using namespace std;

multiset <int> s;
int k, n, res;
pair <int, int> a[200000];

int main(){
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  sort(a, a + n, [](const pair <int, int> &a, const pair <int, int> &b){
    return a.second < b.second;
  });

  for(int i = 0; i < k; i++) s.insert(0);
  for(int i = 0; i < n; i++){
    auto it = s.upper_bound(a[i].first);
    if(it == s.begin()) continue;
    s.erase(--it);
    s.insert(a[i].second);

    res++;
  }

  cout << res;
}
