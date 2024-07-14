#include <bits/stdc++.h>
using namespace std;

struct heap
{
  multiset<int> l, r;
  long long sumLeft = 0, sumRight = 0;
  int median()
  {
    return *l.rbegin();
  }

  void balance()
  {
    while (l.size() > r.size())
    {
      int x = *l.rbegin();
      sumLeft -= x;
      sumRight += x;
      l.erase(l.find(x));
      r.insert(x);
    }
    while (r.size() > l.size())
    {
      int x = *r.begin();
      sumRight -= x;
      sumLeft += x;
      r.erase(r.find(x));
      l.insert(x);
    }
  }

  void ins(int x)
  {
    if (!l.empty() && *(l.rbegin()) >= x)
      sumLeft += x,
      l.insert(x);
    else
      sumRight += x,
      r.insert(x);

    balance();
  }

  void del(int x)
  {
    auto it = l.find(x);
    if (it != l.end())
    {
      sumLeft -= x;
      l.erase(it);
      balance();
      return;
    }

    it = r.find(x);
    if (it != r.end())
      sumRight -= x,
      r.erase(it);

    balance();
  }

  void display()
  {
    if (l.empty() && r.empty())
    {
      cout << "Empty heap" << endl;
      return;
    }
    for (int i : l)
      cout << i << ' ';
    cout << "->";
    for (int i : r)
      cout << i << ' ';
    cout << '\n';
    cout << "-----------------" << '\n';
  }
} pq;

int a[200005];

int main()
{
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    pq.ins(a[i]);
    if (i - k + 1 >= 1)
    {
      pq.del(a[i - k]);
      int med = pq.median();
      long long ans = 1ll * pq.l.size() * med - pq.sumLeft + pq.sumRight - 1ll * pq.r.size() * med;
      cout << ans << " ";
    }
    
  }

  return 0;
}