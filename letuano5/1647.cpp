#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int SIZE = 500;

int a[N];
int bl[N / SIZE + 5];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;

  memset(bl, 0x3f, sizeof(bl));

  for(int i = 0; i < n; i++)
    cin >> a[i],
    bl[i / SIZE] = min(bl[i / SIZE], a[i]);

  while(q--){
    int l, r;
    cin >> l >> r;
    --l, --r;

    int L = l / SIZE;
    int R = r / SIZE;

    // assert(L == R);

    if(L == R)
      cout << *min_element(a + l, a + r + 1) << '\n';
    else{
      int ans = 1e9 + 6969;

      for(int i = L + 1; i <= R - 1; i++)
        ans = min(ans, bl[i]);
      for(int i = l, endP = (L + 1) * SIZE - 1; i <= endP; i++)
        ans = min(ans, a[i]);
      for(int i = R * SIZE; i <= r; i++)
        ans = min(ans, a[i]);

      cout << ans << '\n';
    }
  }

  return 0;
}