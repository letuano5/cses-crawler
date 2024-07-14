#include <bits/stdc++.h>
using namespace std;
#define int long long

const int Nmax=2e5+5;

struct Node {
    int lz, ma;
} st[4*Nmax];

void down(int i){
    int t=st[i].lz;

    for(int j : {i*2, i*2+1})
        st[j].lz+=t, st[j].ma+=t;

    st[i].lz=0;
}

int get(int i, int l, int r, int u, int v){
    if(v<l || r<u) return LLONG_MIN;

    if(u<=l && r<=v) return st[i].ma;

    down(i);

    int m=(l+r)/2;

    return max(get(i*2, l, m, u, v), get(i*2+1, m+1, r, u, v));
}

void update(int i, int l, int r, int u, int v, int vl){
    if(v<l || r<u) return ;

    if(u<=l && r<=v) {
        st[i].lz+=vl;
        st[i].ma+=vl;
        return ;
    }

    down(i);

    int m=(l+r)/2;

    update(i*2, l, m, u, v, vl);
    update(i*2+1, m+1, r, u, v, vl);

    st[i].ma=max(st[i*2].ma, st[i*2+1].ma);
}

int a[Nmax];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    long long s=0;
    cin >> n >> q;
    update(1, 0, n, 0, 0, 0);
    for(int i=1; i<=n; i++){
        cin >> a[i];
        s+=a[i];

        update(1, 0, n, i, i, s);
    }

    for(int i=1, num,u,v; i<=q; i++){
        cin >> num >> u >> v;

        if(num==1){
            update(1, 0, n, u, n, v-a[u]);
            a[u]=v;
        }
        else{
            cout << max(get(1, 0, n, u, v)-get(1, 0, n, u-1, u-1), 0LL) << '\n';
        }
    }

    return 0;
}
