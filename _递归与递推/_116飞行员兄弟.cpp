/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-18 14:09:33
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-18 15:56:58
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define x first
#define y second
typedef pair<int,int> PII;

const int N = 5;
char g[N][N],backup[N][N];

int get(int x,int y)
{
    return x*4+y;
}

void turn_one(int x,int y)
{
    if(g[x][y] == '+') g[x][y]='-';
    else g[x][y] = '+';
}

void turn_all(int x,int y)
{
    for(int i = 0; i < 4; i++)
    {
        turn_one(x,i);
        turn_one(i,y);
    }
    turn_one(x,y);
}

int main()
{
    for(int i = 0; i < 4; i++) cin >> g[i];

    vector<PII> res;
    for(int op = 0; op < 1<<16; op++)
    {
        //存取方案
        vector<PII> temp;
        //备份
        memcpy(backup,g,sizeof g);
        //操作
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                //找到数据位为1的位置进行操作
                if(op >> get(i,j) & 1)
                {
                    temp.push_back({i,j});
                    turn_all(i,j);
                }
            }
        }
        //判断灯泡是否全亮
        bool has_closed = false;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(g[i][j] == '+') has_closed = true;
            }
        }
        if(!has_closed)
        {
            if(res.empty() || res.size() > temp.size()) res = temp;
        }

        //还原
        memcpy(g,backup,sizeof g);
    }
    cout << res.size() << endl;
    for(auto op:res) cout <<op.x+1 << " " <<op.y+1 << endl;
}