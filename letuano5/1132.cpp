#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;

vector<int> g[N];
vector<int> child[N];
vector<int> prefix[N], suffix[N];

int par[N];
int down[N], up[N];
bool done[N];

void dfs(int u){
  done[u] = true;
  for(int v : g[u]){
    if(v == par[u])
      continue;

    child[u].push_back(v);

    par[v] = u;
    dfs(v);
    down[u] = max(down[u], down[v] + 1);
  }
}

void dfs1(int u){
  up[u] = max(up[par[u]] + 1, up[u]);

  int id_of_u = lower_bound(child[par[u]].begin(), child[par[u]].end(), u) - child[par[u]].begin();
  if (id_of_u > 0)
    up[u] = max(up[u], prefix[par[u]][id_of_u - 1] + 2);
  if (id_of_u + 1 < child[par[u]].size())
    up[u] = max(up[u], suffix[par[u]][id_of_u + 1] + 2);

  for(int v : child[u])
    dfs1(v);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  for(int i = 1, u, v; i < n; i++){
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  up[0] = -1;
  dfs(1);

  for (int u = 1; u <= n; u++) {
    prefix[u].resize(child[u].size());
    suffix[u].resize(child[u].size());

    sort(child[u].begin(), child[u].end());
    child[u].resize(unique(child[u].begin(), child[u].end()) - child[u].begin());

    for (int j = 0; j < child[u].size(); j++) {
      prefix[u][j] = down[child[u][j]];
      if (j) prefix[u][j] = max(prefix[u][j], prefix[u][j - 1]);
    }

    for (int j = (int)child[u].size() - 1; j >= 0; j--) {
      suffix[u][j] = down[child[u][j]];
      if (j < (int)child[u].size() - 1) suffix[u][j] = max(suffix[u][j], suffix[u][j + 1]);
    }
  }

  dfs1(1);

  int res = 0;
  for(int i = 1; i <= n; i++)
    cout << max(up[i], down[i]) << ' ';
  return 0;
}
