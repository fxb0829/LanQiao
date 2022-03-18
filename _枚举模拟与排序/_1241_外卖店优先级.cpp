#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;

const int N = 100010;
int n,m,T;
int score[N],last[N];  //得分、上次时间点
bool st[N];            //缓存
PII order[N];          //订单

int main(){
    scanf("%d%d%d",&n,&m,&T);
    for(int i = 0; i < m; i++){
        scanf("%d%d",&order[i].x,&order[i].y);
    }
    sort(order,order+m);

    //枚举每个订单
    for(int i = 0; i < m;){
        int j = i;
        //跳过相同店铺的订单
        while(j < m && order[j] == order[i]) j++;
        //处理这个店铺订单或者是这批相同店铺订单的最后一个订单
        //拿到最开始的时刻t和店铺id
        int t = order[i].x,id = order[i].y;
        int cnt = j-i;  //订单数
        i = j;
        //计算开始时候的
        score[id] -= t - last[id] - 1;     //计算开始时候的得分
        if(score[id] < 0) score[id] = 0;   //如果小于0 则置为0
        if(score[id] <= 3) st[id] = false; //如果小于3移除缓存
        //计算现在这段时间的
        score[id] += 2*cnt;                //更新得分
        if(score[id] > 5) st[id] = true;
        last[id] = t;
    }
    
    for(int i = 1; i <= n; i++){
        //对t时候没有订单的店铺进行处理
        if(last[i] < T){
            score[i] -= T-last[i];
            if(score[i] <= 3) st[i] = false;
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        if(st[i]) res++;
    }

    printf("%d\n",res);

    return 0;
}