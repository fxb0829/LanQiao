#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 100010;
int n;
int a[N],b[N],c[N];
int cnt[N],s[N];
int as[N];  //as[i]表示在A中有多少个数小于b[i]
int cs[N];  //cs[i]表示在C中有多少个数大于b[i]

int main(){
    //输入
    scanf("%d",&n);
    //因为数据是从0开始，+1可以让数据从1开始，方便后面的前缀和求解
    for(int i = 0; i < n; i++) scanf("%d",&a[i]),a[i]++; 
    for(int i = 0; i < n; i++) scanf("%d",&b[i]),b[i]++;
    for(int i = 0; i < n; i++) scanf("%d",&c[i]),c[i]++;

    //统计A中的数出现的次数
    for(int i = 0; i < n; i++) cnt[a[i]]++;
    //求A的前缀和
    for(int i = 1; i < N; i++) s[i] = s[i-1]+cnt[i];
    //求as[]
    for(int i = 0; i < n; i++) as[i] = s[b[i]-1];  //找到比b[i]小的数的个数

    //清空cnt[]和s[]
    memset(cnt,0,sizeof cnt);
    memset(s,0,sizeof s);
    //统计C中的数出现的次数
    for(int i = 0; i < n; i++) cnt[c[i]]++;
    //求C的前缀和
    for(int i = 1; i < N; i++) s[i] = s[i-1]+cnt[i];
    //求cs[]
    for(int i = 0; i < n; i++) cs[i] = s[N-1]-s[b[i]]; //找到比b[i]大的数的个数

    //枚举每个b[i]
    LL res = 0;
    for(int i = 0; i < n; i++){
        res += (LL)as[i] * cs[i];  //两个数相乘也有可能爆int
    }
    cout << res << endl;

    return 0;
}