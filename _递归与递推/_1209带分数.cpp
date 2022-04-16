/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-17 10:48:23
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-18 16:06:30
 */
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;

int n;
bool st[N],backup[N];
int ans;

bool check(int a,int c)
{
    long long b = n * (long long)c-a * (long long)c;
    if(!a || !b || !c) return false;
    memcpy(backup,st,sizeof st);
    //判断数字b的每一位是否有使用过的
    while (b)
    {
        int x = b % 10; //取个位数
        b /= 10;        //去个位数
        //不能包含0或者之前已经出现
        if(!x || backup[x]) return false;
        backup[x]  = true; //标记该数
    }
    //遍历查看是否每个数都出现过
    for(int i = 1; i <= 9; i++)
    {
        if(!backup[i]) return false;
    }
    return true;
    
}

void dfs_c(int u,int a,int c)
{
    if(u == n)return;
    if(check(a,c)) ans++;
    for(int i = 1; i <= 9; i++)
    {
        if(!st[i])
        {
            st[i] = true;
            dfs_c(u+1,a,c*10+i);
            st[i] = false;
        }
    }
}

//n = a+b/c
//u表示当前已经用了几个数字，a表示当前a的枚举值
void dfs_a(int u, int a)
{
    if(a >= n) return;
    //枚举c的值
    dfs_c(u,a,0);

    for(int i = 1; i <= 9; i++)
    {
        if(!st[i])
        {
            st[i] = true;
            dfs_a(u+1,a*10+i);
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs_a(0,0);
    cout << ans << endl;

    return 0;
}