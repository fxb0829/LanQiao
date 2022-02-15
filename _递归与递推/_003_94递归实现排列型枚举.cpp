/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-15 12:42:56
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-15 12:59:42
 */

#include <cstdio>
#include <cstring>
#include <istream>
#include <algorithm>
using namespace std;

const int N = 10;
int n;
int state[N]; //0表示还没放置数
bool used[N]; //true表示已经使用

void dfs(int u)
{
    if(u > n)
    {
        for(int i = 1; i <= n; i++)
        {
            printf("%d ",state[i]);
            
        }
        puts("");
        return;
    }

    //以此枚举每个分支，即当前位置可以填哪些数
    for(int i = 1; i <= n; i++){
        if(!used[i])
        {
            state[u] = i;
            used[i] =true;
            dfs(u+1);
            //恢复现场
            state[u] = 0;
            used[i] = false;
        }
    }
}

int main()
{
    scanf("%d",&n);
    dfs(1);

    return 0;
}