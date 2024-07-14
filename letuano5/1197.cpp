#include<bits/stdc++.h>
using namespace std;

void debug_out() { cerr << '\n'; }
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
  cerr << " " << H;
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int MAX_N = 2505;
const long long INF = 1e18;

struct Edge{
  int u, v, w;

  Edge(int _u = 0, int _v = 0, int _w = 0) {
    u = _u,
    v = _v,
    w = _w;
  }
} edges[MAX_N * 2];

int n, m;
vector<pair<int, int>> g[MAX_N];
int trace[MAX_N];
bool done[MAX_N];
long long d[MAX_N];

bool findNegCycle(int st){
  for(int u = 1; u <= n; u++)
    d[u] = INF,
    trace[u] = -1;

  d[st] = 0;

  int negStart = -1;

  for(int i = 1; i <= n; i++){
    bool relaxed = false;
    negStart = -1;

    for(int j = 1; j <= m; j++){
      auto &[u, v, w] = edges[j];
      if(d[u] != INF && d[v] > d[u] + w){
        relaxed = true;
        trace[v] = u;
        negStart = v;
        d[v] = max(-INF, d[u] + w);
      }
    }

    if(!relaxed)
      return false;
  }

//  iota(trace + 1, trace + 1 + n, 1);

  if(negStart == -1)
    return false;

  cout << "YES\n";
  int u = negStart;
  for(int i = 1; i <= n; i++)
    u = trace[u];

  vector<int> cycle = {u};
  for(int v = trace[u]; v != u; v = trace[v])
    cycle.push_back(v);
  reverse(cycle.begin(), cycle.end());

  for(int i: cycle)
    cout << i << ' ';
  cout << cycle.front();

  return true;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for(int i = 1, u, v, w; i <= m; i++){
    cin >> u >> v >> w;
    edges[i] = {u, v, w};
    g[u].push_back({v, w});
//    g[v].push_back({u, w});
  }

  for(int u = 1; u <= n; u++)
    d[u] = INF;

  for(int u = 1; u <= n; u++){
    if(done[u])
      continue;

    if(findNegCycle(u))
      return 0;
    for(int v = 1; v <= n; v++)
      if(d[v] != INF)
        done[v] = true;
  }

  cout << "NO";
  return 0;
}
