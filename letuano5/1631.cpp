#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long a[n+1],s(0);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s+=a[i];
	}
	sort(a+1,a+n+1);
	cout << max(s,a[n]*2);
	return 0;
}
