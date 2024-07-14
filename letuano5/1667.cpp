#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;

vector<int> adj[MAX];
int d[MAX], tr[MAX];

void trace(int u, int n){
  if(u == n) {
    cout << u << ' ';
    return;
  }
  trace(tr[u], n);
  cout << u << ' ';
}

int main(){
  int n, m;
  for(cin >> n >> m; m--; ){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<int> q;
  q.push(1); d[1] = 1;
  while(!q.empty()){
    int u = q.front(); q.pop();

    //if(u == n) break;

    for(int v: adj[u])
      if(!d[v])
        d[v] = d[u] + 1,
        tr[v] = u,
        q.push(v);
  }

  if(n == 1) cout << 1;
  else if(!d[n]) cout << "IMPOSSIBLE";
  else {
    cout << d[n] << '\n';
    trace(n, 1);
  }
}
