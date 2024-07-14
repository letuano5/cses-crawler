#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200000], res;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for(int i = 0; i < n; i++)
    res += abs(a[n / 2] - a[i]);
  cout << res;
}
