#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 200010;
int n,m;
int a[N];

int main(){
    scanf("%d%d",&n,&m);
    int k = n + m + 1;
    for(int i = 0; i < k; i++) scanf("%d",&a[i]);
    
    LL res = 0;
    if(!m){
        for(int i = 0; i < k; i++) res += a[i];
    }else{
        sort(a,a+k); //也可以不排序，找到最大值最小值就可以
        res = a[k-1]-a[0];
        for(int i = 1; i < k-1; i++) res += abs(a[i]);
    }
    printf("%lld",res);

    return 0;
}