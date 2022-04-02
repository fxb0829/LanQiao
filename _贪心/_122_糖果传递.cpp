#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 1000010;
int n;
int a[N];
LL c[N];

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);

    LL sum = 0;
    for(int i = 1; i <= n; i++) sum += a[i];
    //平均值
    LL avg = sum / n;

    cout << avg << endl;
    //求每个ci
    for(int i = n; i > 1; i--){
        c[i] = c[i+1] + avg - a[i];
    }
    c[1] = 0;

    //排序
    sort(c+1,c+n+1);
    //结果计算
    LL res = 0;
    int mid = c[(n+1)>>1];
    for(int i = 1; i <= n; i++) {
        res += abs(c[i]-mid);
    }
    printf("%lld\n",res);
    return 0;
}