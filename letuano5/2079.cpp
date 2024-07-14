#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int child[N];
bool done[N];
vector<int> g[N];

void dfs(int u){
  done[u] = true;
  child[u] = 1;

  for(int v : g[u]){
    if(done[v])
      continue;

    dfs(v);
    child[u] += child[v];
  }
}

int getCentroid(int u){
  done[u] = true;
  for(int v : g[u])
    if(!done[v]){
      if(child[v] * 2 > n)
        return getCentroid(v);
    }

  return u;
}

int main(){
  cin >> n;
  for(int i = 1, u, v; i < n; i++)
    cin >> u >> v,
    g[u].push_back(v),
    g[v].push_back(u);

  dfs(1);
  memset(done, 0, sizeof(done));
  cout << getCentroid(1);
  return 0;
}