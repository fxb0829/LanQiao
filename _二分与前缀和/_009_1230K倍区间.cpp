/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-22 12:46:37
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-22 12:59:50
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5+10;

int n,k;
LL s[N],cnt[N];

int main()
{
    scanf("%d %d",&n,&k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld",&s[i]);
        s[i] += s[i-1];
    }
    LL res = 0;
    cnt[0] = 1; //第一个数出现模0的情况
    for(int i = 1; i <= n; i++)
    {
        res += cnt[s[i] % k];
        cnt[s[i] % k]++;
    }
    printf("%lld\n",res);
    
    return 0;
}