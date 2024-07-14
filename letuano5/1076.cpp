#include<bits/stdc++.h>
using namespace std;

struct heap{
  multiset<int> l, r;
  int median(){
    return *l.rbegin();
  }

  void balance(){
    while(l.size() > r.size()){
      int x = *l.rbegin();
      l.erase(l.find(x));
      r.insert(x);
    }
    while(r.size() > l.size()){
      int x = *r.begin();
      r.erase(r.find(x));
      l.insert(x);
    }
  }

  void ins(int x){
    if(!l.empty() && *(l.rbegin()) >= x) l.insert(x);
    else r.insert(x);

    balance();
  }

  void del(int x){
    auto it = l.find(x);
    if(it != l.end()) {
      l.erase(it);
      balance();
      return;
    }

    it = r.find(x);
    if(it != r.end()) r.erase(it);

    balance();
  }

  void display(){
    if(l.empty() && r.empty()){
      cout << "Empty heap" << endl;
      return;
    }
    for(int i: l) cout << i << ' ';
    cout << "->";
    for(int i: r) cout << i << ' ';
    cout << '\n';
    cout << "-----------------" << '\n';
  }
} pq;

int a[200005];

int main(){
  int n, k;
  cin >> n >> k;

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    pq.ins(a[i]);
    if(i - k + 1 >= 1){
      pq.del(a[i - k]);
      cout << pq.median() << ' ';
    }
  }

  return 0;
}
