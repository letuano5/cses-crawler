#include <bits/stdc++.h>
using namespace std;
struct element{
  int value;
  int index;
};

vector <element> arr;

int main(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    int input;
    cin >> input;
    while(arr.size() > 0 && arr.back().value >= input)
      arr.pop_back();
    if(arr.size() == 0) cout << 0 << ' ';
    else cout << arr.back().index << ' ';
    arr.push_back({input, i});
  }
}
