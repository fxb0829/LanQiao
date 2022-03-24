#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10010;
int n;
int b[N];
bool st[N];

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&b[i]);

    //统计环的个数
    int cnt = 0;
    //注意：这里是从瓶子1开始找，不是索引1
    for(int i = 1; i <= n; i++){
        if(!st[i]){ //这个点没有找过,新的环
            cnt++;  //新环+1
            //找到一个完整的环
            for(int j = i; !st[j]; j = b[j]){
                st[j] = true;
            }
        }
    }
    printf("%d\n",n-cnt);
    return 0;
}