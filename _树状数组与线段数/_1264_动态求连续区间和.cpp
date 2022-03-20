#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int n,m;
int a[N],tr[N];

int lowbit(int x){
    return x & -x;
}

void add(int x,int v){ 
    for(int i = x; i <= N; i += lowbit(i)) tr[i] += v;
}

int query(int x){
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);

    //原始数组初始化为树状数组
    for(int i = 1; i <= n; i++) add(i,a[i]);

    //执行操作
    while(m--){
        int k,x,y;
        scanf("%d%d%d",&k,&x,&y);
        if(k == 0) printf("%d\n",query(y)-query(x-1));
        else add(x,y);
    }

    return 0;
}