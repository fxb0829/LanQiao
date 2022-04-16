/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-18 10:19:27
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-18 13:55:40
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 6;
//存储数组
char g[N][N],backup[N][N];
//偏移量数组
int dx[5] = {-1,0,1,0,0},dy[5] = {0,1,0,-1,0};

void turn(int x,int y)
{
    for(int i = 0; i < 5; i++)
    {
        int a = x + dx[i],b = y + dy[i];
        //边界判断
        if(a < 0 || a >= 5 || b < 0 || b >= 5) continue;
        g[a][b] ^= 1; //二进制下只有最后一位不同，异或1就可以改变
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        //读入棋盘（每次读取一个字符串）
        for(int i = 0; i < 5; i++) cin >> g[i];
        //定义结果（最大为6）
        int res = 10;
        //操作
        for(int op = 0; op < 32; op++)
        {
            //备份
            memcpy(backup,g,sizeof g);
            int step = 0;
            //枚举第一行
            for(int i = 0; i < 5; i++)
            {
                //判断第一行的位 判断下一行的位置是否需要操作，1不操作，0操作
                if(!(op >> i & 1))
                {
                    step++;
                    turn(0,i);
                }
            }
            //剩下的行
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    //当前的灯是灭的，那么下一行的当前位置肯定要操作
                    if(g[i][j] == '0')
                    {
                        step++;
                        turn(i+1,j);
                    }
                }
            }
            bool dark = false;
            //根据最后一行判断灯是否全亮
            for(int i = 0; i < 5; i++)
            {
                if(g[4][i] == '0')
                {
                    dark = true;
                    break;
                }
            }
            if(!dark) res = min(res,step);
            //还原
            memcpy(g,backup,sizeof g);
        }
        if(res > 6) res = -1;
        cout << res << endl;
    }
    
    return 0;
}