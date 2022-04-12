#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 100010,mod = 1000000009;
int n,k;
int a[N];

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i++) scanf("%d",&a[i]);
    sort(a,a+n);

    int res = 1;
    int l = 0,r = n-1;
    int sign = 1;
    if(k % 2){
        //取最后
        res = a[r--];
        k--;
        if(res < 0) sign = -1;
    }
    while(k){
        LL x = (LL)a[l]*a[l+1],y = (LL)a[r-1]*a[r];
        //如果sign为-1，则说明全是负数，那么要尽可能取大的
        //如果sign为1，则说明最后结果是正数，那么要取乘积最大的
        if(x*sign > y*sign){
            res = x % mod * res % mod;
            l += 2;
        }else{
            res = y % mod * res % mod;
            r -= 2;
        }
        k -= 2;
    }
    printf("%d\n",res);

    return 0;
}