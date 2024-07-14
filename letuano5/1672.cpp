#include<bits/stdc++.h>
using namespace std;

const int N = 505;
typedef pair<long long, int> Node;

int n, m, q;

vector<pair<int, int>> adj[N];
long long dist[N][N];


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> q;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      if(i != j) dist[i][j] = 1e18;

  while(m--){
    int u, v;
    long long c;
    cin >> u >> v >> c;

    dist[u][v] = dist[v][u] = min(dist[u][v], c);
  }

  for(int k = 1; k <= n; k++)
    for(int u = 1; u <= n; u++)
      for(int v = 1; v <= n; v++)
        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);

  while(q--){
    int u, v;
    cin >> u >> v;

    cout << (dist[u][v] == 1e18 ? -1 : dist[u][v]) << '\n';
  }

  return 0;
}
