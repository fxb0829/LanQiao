/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-20 15:59:43
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-20 16:12:50
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int nums[N];  //表示原始数组
int s[N];     //表示前缀和数组

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&nums[i]);
        s[i] = s[i-1] + nums[i];
    }
    while(m--)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);
    }
    return 0;
}

