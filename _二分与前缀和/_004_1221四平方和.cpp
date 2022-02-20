/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-20 14:13:17
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-20 15:06:36
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define x first
#define y second

using namespace std;

typedef pair<int,int> PII;

const int N = 2500010;

unordered_map<int,PII> S;
int n,m;

int main()
{
    cin >> n;
    for(int c = 0; c*c <= n; c++)
    {
        for(int d = c; c*c + d*d <= n; d++)
        {
            int t = c*c + d*d;
            //第一个存储的就是字典序最小的
            if(S.count(t) == 0) S[t] = {c,d};
        }
    }
    for(int a = 0; a*a <= n; a++)
    {
        for(int b = a; a*a + b*b <= n; b++)
        {
            int t = n-a*a-b*b;
            if(S.count(t))
            {
                printf("%d %d %d %d\n",a,b,S[t].x,S[t].y);
                return 0;
            }
        }
    }
    return 0;
}
