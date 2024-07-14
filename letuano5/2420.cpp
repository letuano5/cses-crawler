#include<bits/stdc++.h>
using namespace std;

#define int long long

void debug_out() { cerr << '\n'; }
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
  cerr << " " << H;
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int BASE = 31;
const int MOD = 1e9 + 2277;
const int N = 2e5 + 5;

long long pw[N];

struct HashSeg {
  struct Node{
    int val = 0, len = 0;
    Node(int v = 0, int leng = 0){
      val = v; len = leng;
    }
    bool operator == (const Node &c) const {
      return len == c.len && val == c.val;
    }
  };

  string s;
  int n;
  vector <Node> st;

  HashSeg (string _s) {
    s = _s;
    n = s.size();
    s = ' ' + s;
    st.assign(4 * n + 5, Node());
  }

  Node merge(Node a, Node b){
    Node ans;
    ans.val = (a.val * pw[b.len] + b.val) % MOD;
    ans.len = a.len + b.len;
    return ans;
  }

  void build(int id, int l, int r){
    if(l == r){
      st[id] = Node(s[l] - 'a' + 1, 1);
      return;
    }

    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = merge(st[id << 1], st[id << 1 | 1]);
  }

  Node get(int id, int l, int r, int u, int v){
    if(v < l || r < u)
      return Node();

    if(u <= l && r <= v)
      return st[id];

    int mid = (l + r) >> 1;
    return merge(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
  }

  void update(int id, int l, int r, int u, int v, int val){
    if(v < l || r < u)
      return;
    if(u <= l && r <= v){
      st[id].val = val;
      return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    st[id] = merge(st[id << 1], st[id << 1 | 1]);
  }

  void update (int l, int r, char ch) {
    update(1, 1, n, l, r, ch - 'a' + 1);
  }

  long long get (int l, int r) {
    return get(1, 1, n, l, r).val;
  }
};


int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;

  pw[0] = 1;
  for (int i = 1; i < N; i++) {
    pw[i] = pw[i - 1] * BASE % MOD;
  }

  string s;
  cin >> s;

  string rev_s = s;
  reverse(rev_s.begin(), rev_s.end());

  HashSeg seg(s), rev_seg(rev_s);
  seg.build(1, 1, n);
  rev_seg.build(1, 1, n);

  s = ' ' + s;
  rev_s = ' ' + rev_s;

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int k; char x;
      cin >> k >> x;
      s[k] = x;
      rev_s[n - k + 1] = x;
      seg.update(k, k, x);
      rev_seg.update(n - k + 1, n - k + 1, x);
    }
    else {
      int l, r;
      cin >> l >> r;

      long long cur_hash = seg.get(1, 1, n, l, r).val;
      long long rev_hash = rev_seg.get(1, 1, n, n - r + 1, n - l + 1).val;
      cout << (cur_hash == rev_hash ? "YES\n" : "NO\n");
    }
  }

  return 0;
}
