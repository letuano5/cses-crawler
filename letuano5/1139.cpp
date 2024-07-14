#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int c[N];
set<int> s[N];
int res[N];
bool done[N];

void dfs(int u){
  done[u] = true;
  s[u].insert(c[u]);

  for(int v : g[u]){
    if(done[v])
      continue;

    dfs(v);
    if(s[u].size() < s[v].size())
      s[u].swap(s[v]);
    s[u].insert(s[v].begin(), s[v].end());
  }

  res[u] = s[u].size();
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for(int i = 1; i <= n; i++)
    cin >> c[i];

  for(int i = 1, u, v; i < n; i++)
    cin >> u >> v,
    g[u].push_back(v),
    g[v].push_back(u);

  dfs(1);
  
  for(int i = 1; i <= n; i++)
    cout << res[i] << " ";

  return 0;
}