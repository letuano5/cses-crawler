#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string res;
    int count = 0;
    do {
        count++;
        res += s;
        res += '\n';
    } while(next_permutation(s.begin(), s.end()));

    cout << count << '\n';
    cout << res;
    return 0;
}
