
// 树状数组：
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// using namespace std;

// const int N = 100010;
// int n,m;
// int a[N],tr[N];

// int lowbit(int x){
//     return x & -x;
// }

// void add(int x,int v){ 
//     for(int i = x; i <= N; i += lowbit(i)) tr[i] += v;
// }

// int query(int x){
//     int res = 0;
//     for(int i = x; i > 0; i -= lowbit(i)) res += tr[i];
//     return res;
// }

// int main(){
//     scanf("%d%d",&n,&m);
//     for(int i = 1; i <= n; i++) scanf("%d",&a[i]);

//     //原始数组初始化为树状数组
//     for(int i = 1; i <= n; i++) add(i,a[i]);

//     //执行操作
//     while(m--){
//         int k,x,y;
//         scanf("%d%d%d",&k,&x,&y);
//         if(k == 0) printf("%d\n",query(y)-query(x-1));
//         else add(x,y);
//     }

//     return 0;
// }

// 线段树
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
    int sum;
} tr[N*4];

void pushhub(int u){
    // u << 1 等同于 2u
    //u << 1 | 1 等同于 2u+1
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u,int l,int r){
    if(l == r) tr[u] = {l,r,w[r]};
    else{
        //初始化
        tr[u] = {l,r};
        int mid = (l+r)>>1;
        //处理左子节点
        build(u<<1,l,mid);
        //处理右子节点
        build(u<<1|1,mid+1,r);
        //更新求和
        pushhub(u);
    }
}

int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    
    int mid = tr[u].l+tr[u].r >> 1;
    int sum = 0;
    if(l <= mid) sum += query(u<<1,l,r);
    if(r > mid) sum += query(u << 1 | 1,l,r);
    return sum;
}

void modify(int u,int x,int v){
    //如果现在在叶子结点，说明已经找到
    if(tr[u].l == tr[u].r) tr[u].sum += v;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1,x,v);
        else modify(u << 1 | 1,x,v);
        pushhub(u);
    }
}


int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) scanf("%d",&w[i]);
    //初始化构建线段树
    build(1,1,n);

    //操作
    int k,a,b;
    while(m--){
        scanf("%d%d%d",&k,&a,&b);
        if(k == 0) printf("%d\n",query(1,a,b));
        else modify(1,a,b);
    }

    return 0;
}