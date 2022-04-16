/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-20 12:50:09
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-20 13:37:00
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int h[N];

bool check(int e)
{
    for(int i = 1; i <= n; i++)
    {
        e = e * 2 - h[i];
        if(e >= 1e5) return true;
        if(e < 0) return false;
    }
    return true;
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&h[i]);
    
    int l = 0,r = 1e5;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n",r);

    return 0;
}
