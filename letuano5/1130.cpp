#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

// f[u][1] -> số lượng ghép lớn nhất chọn được trong cây con gốc u sao cho u được ghép với cha của u
// f[u][0] -> số lượng ghép lớn nhất chọn được trong cây con gốc u sao cho u KHÔNG được ghép với cha của u

// f[u][1] = SUM(f[v][0], v là con của u) -> u đã ghép với cha của u, nên con v của u không được ghép,
// nên giá trị lớn nhất ở mỗi nhánh là f[v][0].

// f[u][0] = MAX (SUM(f[v][0])  -> Không ghép u với cả cha lẫn con.
//     SUM(f[v][0]) - f[v][0] + f[v][1] + 1 -> Ghép v với u => Tất cả các v khác không được ghép


int dp[N][2];
vector<int> g[N];

void dfs(int u, int p = -1){
  int cur = 0;
  for(int v: g[u]){
    if(v == p) continue;

    dfs(v, u);
    cur += dp[v][0];
  }

  if(p != -1)
    dp[u][1] = cur;

  dp[u][0] = cur;
  for(int v: g[u])
    if(v != p)
      dp[u][0] = max(dp[u][0], cur - dp[v][0] + dp[v][1] + 1);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for(int i = 1; i < n; i++){
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1);
  cout << dp[1][0];

  return 0;
}
