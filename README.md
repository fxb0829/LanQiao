<!--
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-16 11:03:24
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-16 11:14:34
-->
# LanQiao

## 测试

***

```C++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 16;

int n;
int st[N]; //状态，记录每个位置当前的状态，0表示还没考虑，1表示选他，2表示不选它
vector<vector<int>> ways; //记录方案

void dfs(int u){
    if(u > n)
    {
        //当前方案
        vector<int> way;
        for (int i = 1; i <= n; i++)
        {
            if(st[i] == 1){
                //记录方案
                way.push_back(i);
            }
        }
        ways.push_back(way);
        return;
    }

    st[u] = 2;
    dfs(u + 1);  //第一个分支，不选
    st[u] = 0;   //恢复现场

    st[u] = 1;
    dfs(u + 1); //第二个分支，选
    st[u] = 0;
}

int main()
{
    cin >> n;
    dfs(1);

    //输出方案
    for(int i = 0; i < ways.size(); i++){
        for(int j = 0; j < ways[i].size(); j++){
            printf("%d ",ways[i][j]);
        }
        puts("");
    }

    return 0;
}
```
