#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 1000010;
int n;
int h[N],tr[N];
int sum[N];

int lowbit(int x){
    return x & -x;
}

void add(int x,int v){
    for(int i = x; i < N; i += lowbit(i)) tr[i] += v;
}

int query(int x){
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
    scanf("%d",&n);
    //身高均+1,保证从1开始
    //树状数组的下标是从1开始的
    for(int i = 0; i < n; i++) scanf("%d",&h[i]),h[i]++;

    //求每个数前面有多少个数比当前的数大
    for(int i = 0; i < n ;i++){
        sum[i] = query(N-1)-query(h[i]);
        add(h[i],1);
    }
    //清空树状数组
    memset(tr,0,sizeof tr);

    //求后面每个数有多少个比当前的数小
    for(int i = n-1; i >= 0; i--){
        sum[i] += query(h[i]-1);
        add(h[i],1);
    }

    LL res = 0;
    for(int i = 0; i < n ; i++) res += (LL)sum[i]*(sum[i]+1)/2;

    printf("%lld\n",res);

    return 0;
}