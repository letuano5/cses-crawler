#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int a[200005];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ordered_set s;

  int n, q;
  cin >> n >> q;

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    s.insert(a[i]);
  }

  while(q--){
    char query;
    cin >> query;

    if(query == '?'){
      int l, r;
      cin >> l >> r;

      cout << s.order_of_key(r + 1) - s.order_of_key(l) << '\n';
    }

    else{
      int id, val;
      cin >> id >> val;
      s.erase(s.upper_bound(a[id]));
      s.insert(val);
      a[id] = val;
    }
  }

  return 0;
}
