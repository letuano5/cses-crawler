#include <bits/stdc++.h>
using namespace std;
 
int sum[200005], a[200005];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] ^= a[i - 1];
    //for (int i = 1; i <= n; i++)
    //    sum[i] = sum[i - 1] ^ a[i];
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << (a[v] ^ a[u - 1]) << '\n';
    }
    return 0;
}