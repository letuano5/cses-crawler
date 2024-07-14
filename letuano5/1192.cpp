#include<bits/stdc++.h>
using namespace std;

char a[1001][1001]; int n, m, c[1001][1001], res;

void dfs(int i, int j){
  if(i < 1 || i > n || j < 1 || j > m) return;
  if(a[i][j] == '#') return;
  if(c[i][j]) return;

  a[i][j] = '#', c[i][j] = res;
  dfs(i, j + 1);
  dfs(i + 1, j);
  dfs(i, j - 1);
  dfs(i - 1, j);
}

int main(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) cin >> a[i][j];

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      if(!c[i][j] && a[i][j] != '#'){
        ++res;
        dfs(i, j);
      }

  cout << res;

  return 0;
}
