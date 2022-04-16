/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-21 20:24:31
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-21 23:26:07
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;

int n,r;
int s[N][N];

int main()
{
    scanf("%d %d",&n,&r);
    r = min(5001,r);   //r可能超出范围
    for(int i = 0; i < n; i++)
    {
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        s[++x][++y] += w;
    }
    for(int i = 1; i <= 5001; i++)
    {
        for(int j = 1; j <= 5001; j++)
        {
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
        }
    }
    int max = 0;
    for(int i = r; i <= 5001; i++)
    {
        for(int j = r; j <= 5001; j++)
        {
            int temp = s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r];
            if(temp > max) max = temp;
        }
    }
    printf("%d\n",max);
    return 0;
}

