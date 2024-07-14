#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main(){
  string s;
  cin >> s;

  for(char c : s)
    cnt[c - 'A']++;

  if(count_if(cnt, cnt + 26, [](int i){return i & 1;}) > 1)
    return cout << "NO SOLUTION", 0;

  int pos = -1;
  for(int i = 0; i < 26; i++)
    if(cnt[i] & 1)
      pos = i;

  string top = "", mid = "";
  for(int i = 0; i < 26; i++)
    if(pos != i)
        for(int j = 1; j <= (cnt[i] >> 1); j++)
          top += char(i + 'A');

  if(pos != -1)
    while(cnt[pos]--)
      mid += char(pos + 'A');

  cout << top << mid;
  reverse(top.begin(), top.end());
  cout << top;
}
