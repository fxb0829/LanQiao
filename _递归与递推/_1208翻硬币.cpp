/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-18 14:15:18
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-18 14:48:47
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100;
int n;
char start[N],target[N];

void turn(int i)
{
    if(start[i] == '*') start[i] = 'o';
    else start[i] = '*';
}

int main()
{
    cin >> start >> target;
    n = strlen(start);

    int res = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(start[i] != target[i])
        {
            //反转
            turn(i),turn(i+1);
            res++;
        }
    }
    cout << res << endl;

    return 0;
}