/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-15 14:25:25
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-15 14:52:06
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<int> nums;
vector<vector<int>> ways;

void dfs(int u)
{
    //超出个数以及个数不够的情况
    if(nums.size() > m || nums.size() + (n-u+1) < m) return;
    if(u == n + 1)
    {
        ways.push_back(nums);
        return;
    }

    nums.push_back(u);  //选择当前的数
    dfs(u+1);
    //恢复现场
    nums.pop_back();
    dfs(u+1);           //不选择当前的数
}

int main()
{
    scanf("%d %d",&n,&m);
    dfs(1);

    //输出结果
    for(int i = 0; i < ways.size(); i++)
    {
        for(int j = 0; j < ways[i].size(); j++)
        {
            printf("%d ",ways[i][j]);
        }
        puts("");
    }
    return 0;
}