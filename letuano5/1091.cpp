#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	multiset<int> a;
	for(int i = 0; i < n; i++){
		int l;
		cin >> l;
		a.insert(l);
	}
	// tim gtln <= maxprice => tim min > maxprice
	for(int i = 0; i < m; i++){
		int l;
		cin >> l;
		auto it = a.upper_bound(l);
		if(it == a.begin()){
			cout << -1 << endl;
        }
		else{
            it--;
            cout << *it << endl;
            a.erase(it);
		}
	}
	return 0;
}
