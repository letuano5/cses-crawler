#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void add_mod (int& a, int b) {
  if ((a += b) >= MOD)
    a -= MOD;
}

struct TrieNode {
  TrieNode* child[26];
  int cnt;

  TrieNode() {
    for (int i = 0; i < 26; i++)
      child[i] = NULL;
    cnt = 0;
  }
};

TrieNode* root = new TrieNode();

void add (const string& s) {
  TrieNode* u = root;
  for (char ch : s) {
    int id = ch - 'a';
    if (u->child[id] == NULL) {
      u->child[id] = new TrieNode();
    }
    u = u->child[id];
  }
  u->cnt++;
}


int f[5005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;

  int n = s.size();
  s = ' ' + s;

  int k;
  cin >> k;

  while (k--) {
    string s;
    cin >> s;
    add(s);
  }

  f[0] = 1;
  for (int i = 0; i <= n; i++) {
    if (f[i] == 0)
      continue;
    TrieNode* u = root;
    for (int j = i + 1; j <= n; j++) {
      int id = s[j] - 'a';
      if (u->child[id] == NULL)
        break;
      u = u->child[id];
      if (u->cnt > 0) {
        add_mod(f[j], f[i]);
      }
    }
  }

  cout << f[n];
  return 0;
}
