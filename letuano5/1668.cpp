#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

int n, m, res[MAX];
vector<int> adj[MAX];

void dfs(int u){
  if(!res[u]) res[u] = 1;

  for(int v: adj[u])
    if(!res[v]){
      res[v] = (res[u] == 1 ? 2 : 1);
      dfs(v);
    } else if(res[v] == res[u]){
      cout << "IMPOSSIBLE";
      exit(0);
    }
}

int main(){
  cin >> n >> m;

  for(int i = 1; i <= m; i++){
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 1; i <= n; i++)
    if(!res[i]) dfs(i);

  for(int i = 1; i <= n; i++)
    cout << res[i] << ' ';
}
