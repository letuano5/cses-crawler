#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int MAX = 1001,
          dx[] = {+0, +0, -1, +1},
          dy[] = {-1, +1, +0, +0};
const char dir[] = {'L', 'R', 'U', 'D'};

char a[MAX][MAX], trc[MAX][MAX]; int dist[MAX][MAX];
pair<int, int> tr[MAX][MAX];

void trace(int u, int v, pair<int, int> st){
  if(u == st.x && v == st.y) return;
  trace(tr[u][v].x, tr[u][v].y, st);
  cout << trc[u][v];
}

int main(){
  int n, m;
  cin >> n >> m;

  pair<int, int> st, en;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) {
      cin >> a[i][j];

      if(a[i][j] == 'A') st = {i, j};
      else if(a[i][j] == 'B') en = {i, j};
    }

  if(st == en)
    return !(cout << "YES\n0");

  queue<pair<int, int>> q;
  q.push(st);
  while(!q.empty()){
    auto t = q.front(); q.pop();

    if(t == en) break;

    for(int i = 0; i < 4; i++){
      int xp = t.x + dx[i], yp = t.y + dy[i];

      if(xp < 1 || xp > n || yp < 1 || yp > m || a[xp][yp] == '#' || dist[xp][yp])
        continue;

      dist[xp][yp] = dist[t.x][t.y] + 1;
      tr[xp][yp] = {t.x, t.y};
      trc[xp][yp] = dir[i];
      q.push({xp, yp});
    }
  }

  if(!dist[en.x][en.y]) return !(cout << "NO");
  cout << "YES\n" << dist[en.x][en.y] << '\n';
  trace(en.x, en.y, st);

  return 0;
}
