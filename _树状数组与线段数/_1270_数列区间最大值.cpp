#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int n,m;
int w[N];
struct Node{
    int l,r;
    int maxv; 
}tr[N*4];

void pushhub(int u){
    tr[u].maxv = max(tr[u<<1].maxv,tr[u<<1|1].maxv);
}

void build(int u,int l,int r){
    if(l == r) tr[u] = {l,r,w[l]};
    else{
        tr[u] = {l,r};
        int mid = (l+r) >> 1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushhub(u);
    }
}

int query(int u,int l,int r){
    //区间已经完全包含
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].maxv;
    
    int mid = (tr[u].l + tr[u].r) >> 1;
    int tm = INT32_MIN;
    if(l <= mid) tm = max(query(u<<1,l,r),tm);
    if(r > mid) tm = max(query(u<<1|1,l,r),tm);
    return tm;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) scanf("%d",&w[i]);
    build(1,1,n);

    //查询
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",query(1,a,b));
    }

    return 0;
}