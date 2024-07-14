#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;

struct dsu{
  int p[MAX];

  dsu(){
    memset(p, -1, sizeof(p));
  }

  int root(int u){
    return p[u] < 0 ? u : p[u] = root(p[u]);
  }

  void combine(int u, int v){
    if((u = root(u)) == (v = root(v))) return;
    if(p[u] > p[v]) swap(u, v);
    p[u] += p[v];
    p[v] = u;
  }
} d;

int main(){
  int n, m;

  for(cin >> n >> m; m--; ){
    int u, v;
    cin >> u >> v;
    d.combine(u, v);
  }

  vector<int> res;
  for(int i = 1; i <= n; i++)
    if(d.p[i] < 0) res.push_back(i);

  cout << res.size() - 1 << '\n';
  for(int i = 0; i < res.size() - 1; i++)
    cout << res[i] << ' ' << res[i + 1] << '\n';
}
