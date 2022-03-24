#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;

const int N = 100010;
int n,d,k;
PII logs[N];
int cnt[N];
bool st[N];

int main(){
    scanf("%d%d%d",&n,&d,&k);
    for(int i = 0; i < n; i++) scanf("%d%d",&logs[i].x,&logs[i].y);
    //排序
    sort(logs,logs+n);
    //具体的操作
    for(int i = 0, j = 0; i < n; i++){
        //遍历一个就要在相应的id++
        int id = logs[i].y;
        cnt[id]++;

        //判断当前的时间窗口是否满足要求
        //不满足则挪动j指针使得满足
        //每次挪动j指针，都要在cnt数组对应的id处-1
        while(logs[i].x-logs[j].x >= d){
            cnt[logs[j].y]--;
            j++;
        }
        //判断当前的id是否出现k次以上
        //是的话则标记一下
        if(cnt[id] >= k) st[id] = true;
    }

    //遍历标记数组，依次输出标记过的
    for(int i = 0; i < 100000; i++){
        if(st[i]) cout << i << endl;
    }
    return 0;
}