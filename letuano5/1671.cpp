#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef pair<long long, int> Node;

vector<pair<int, int>> adj[N];
long long d[N];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  while(m--){
    int u, v, c;
    cin >> u >> v >> c;

    adj[u].push_back({v, c});
//    adj[v].push_back({u, c});
  }

  priority_queue<Node, vector<Node>, greater<Node>> pq;

  memset(d, 0x3f, sizeof(d));
  d[1] = 0;
  pq.push({0, 1});

  while(!pq.empty()){
    auto [du, u] = pq.top();
    pq.pop();

    if(d[u] != du)
      continue;

    for(auto [v, w]: adj[u])
      if(d[v] - d[u] > w)
        d[v] = d[u] + w,
        pq.push({d[v], v});
  }

  for(int i = 1; i <= n; i++)
    cout << d[i] << ' ';

  return 0;
}
