#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int f[N];

void dfs(int u){
  f[u] = 1;
  for(int v : g[u]){
    dfs(v);
    f[u] += f[v];
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for(int i = 2, u; i <= n; i++){
    cin >> u;
    g[u].push_back(i);
  }

  dfs(1);

  for(int i = 1; i <= n; i++)
    cout << f[i] - 1 << ' ';

  return 0;
}
