#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 100010;
int n;
int a[N];

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);

    LL maxs = INT32_MIN;
    int depth  =0;
    for(int d = 1,i = 1; i <= n; i *= 2,d++){
        LL s = 0;
        //起点i加上当前层的个数=共需要遍历的个数
        for(int j = i; j < (1<<d-1)+i && j <= n; j++){
            s += a[j];
        }
        if(s > maxs) maxs = s,depth = d;
    }
    printf("%d\n",depth);
    return 0;
}