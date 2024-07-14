#include <iostream>
using namespace std;

using lo=long long;

lo n,
b[200005]
,x[500005],
q;

void up(int i,lo v)
{
	for(;i<=n;i+=i&-i)b[i]+=v;
}

lo ge(int i)
{
	lo ans=0;
	for(;i>0;i-=i&-i)ans+=b[i];
	return ans;
}

void ur(int l,int r,lo v)
{
	up(l,v);up(r+1,-v);
}

lo gr(int l,int r)
{
	return ge(r)-ge(l-1);
}

int main() {
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>i[x];
		// ur(i,i,x);
	}
	for(int i=1;i<=q;i++)
	{
		int t,a,b,k;
		cin>>t;
		if(t^2)
		{
			cin>>a>>b>>k;
			ur(a,b,k);
		}
		else
		{
			cin>>k;
			cout<<x[k]+ge(k)<<"\n";
		}
	}
	return 0;
}