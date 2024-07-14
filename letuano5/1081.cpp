#include <bits/stdc++.h>
using namespace std;

int n, cnt[1000001], MAX;

int main(){
//  freopen("C:\\Users\\Admin\\Downloads\\test_input.txt", "r", stdin);
  for(cin >> n; n--; ){
    int x;
    cin >> x;
    MAX = max(MAX, x);
    cnt[x]++;
  }
//  cerr << cnt[MAX] << '\n';

  for(int i = MAX; i; --i){
    int c = 0;
    for(int j = i; j <= MAX; j += i) c += cnt[j];
//    if(i == MAX) cout << c << "\n";
    if(c > 1) return !(cout << i);
  }
  return 0;
}

///////////////////////////
/*
#include<bits/stdc++.h>
using namespace std;

#define IOS               ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define int               long long int
#define endl              "\n"

const int N = 1e6 + 1;

int ans[N];

signed main() {
	IOS;
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i ++) {
		cin >> x;
		for (int j = 1; j * j <= x; j ++)
			if (x % j) continue;
			else {
				ans[j] ++;
				if (x / j != j) ans[x / j] ++;
			}
	}
	int mx = 1;

	for (int i = 1; i < N; i ++)
		if (ans[i] > 1) {
			mx = max(i, mx);
		}
	cout << mx;
	return 0;
}
*/
///////////////////////////
