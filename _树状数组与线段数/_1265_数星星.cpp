#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 32010;
int n;
int tr[N],level[N];

int lowbit(int x){
    return x & -x;
}

void add(int x,int v = 1){
    for(int i = x; i <= N; i += lowbit(i)) tr[i] += v;
}

int sum(int x){
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x++; //保证坐标从1开始
        //先查询一下这个星星的x坐标之前有多少颗星星，也就是等级
        //访问到一次就相当于增加一级
        level[sum(x)]++;
        add(x);
    }

    for(int i = 0; i < n; i++){
        printf("%d\n",level[i]);
    }

    return 0;
}