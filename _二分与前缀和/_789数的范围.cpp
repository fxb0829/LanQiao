/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-18 16:38:10
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-18 17:01:52
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int q[N];

int main()
{
    //读入数据
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++) scanf("%d",&q[i]);
    //查询处理
    for(int i = 0; i < m ;i++)
    {
        int x;
        scanf("%d",&x);
        //二分查找
        int l = 0,r = n-1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if(q[mid] >= x) r = mid;
            else l = mid + 1;
        }
        //存在的情况
        if(q[r] == x)
        {
            //输出左端点
            cout << r << ' ';
            //查找右端点
            r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if(q[mid] <= x) l = mid;
                else r = mid - 1;
            }
            //输出右端点
            cout << l << endl;
        }
        else cout << "-1 -1" << endl;
    }
}
