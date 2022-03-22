#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10010;
int n;
//线段
struct Segment {
    int x,y1,y2;  //x坐标，两个点的y坐标
    int k; // +1 或者 -1
    bool operator < (const Segment &t) const{
        return x < t.x;
    }
}seg[N*2];  //有多少矩形就有多少线段

struct Node{
    int l,r;
    int cnt,len;
}tr[N*4];

void pushub(int u){
    //当前节点大于0的话，长度就是右节点-左节点+1
    if(tr[u].cnt > 0) tr[u].len = tr[u].r - tr[u].l + 1;
    //当前节点是叶子结点，长度就是0
    else if(tr[u].l == tr[u].r) tr[u].len = 0;
    //否则，当前节点就是左节点的长度+右节点的长度
    else tr[u].len = tr[u<<1].len + tr[u<<1|1].len;
}

void build(int u,int l,int r){
    tr[u] = {l,r};
    if(l == r) return;
    
    int mid = l + r >> 1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}


void modify(int u,int l,int r,int k){
    //全包含的情况
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].cnt += k; //次数修改
        pushub(u);
    }else{
        int mid = tr[u].l+tr[u].r >> 1;
        if(l <= mid) modify(u<<1,l,r,k);
        if(r > mid) modify(u<<1|1,l,r,k);
        pushub(u);
    }
}

int main(){
    scanf("%d",&n);
    //读入数据并构建线段
    int m = 0;
    for(int i = 0; i < n; i++){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        //每个矩形有两个线段
        seg[m++] = {x1,y1,y2,1};
        seg[m++] = {x2,y1,y2,-1};
    }
    //对所有的线段排序
    sort(seg,seg+m);
    //初始化线段树
    build(1,0,10000);
    
    int res = 0;
    for(int i = 0; i < m; i++){
        //从第二条线开始算
        if(i > 0) res += tr[1].len*(seg[i].x-seg[i-1].x); //高*宽
        //放入当前节点
        modify(1,seg[i].y1,seg[i].y2-1,seg[i].k);
    }
    printf("%d\n",res);
    return 0;
}
