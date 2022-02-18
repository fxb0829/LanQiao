/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-18 17:31:09
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-18 18:12:10
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    double x;
    cin >> x;
    double l = -10000,r = 10000;
    while (r-l > 1e-8)
    {
        double mid = (l+r)/2;
        if(mid*mid*mid >= x) r = mid;
        else l = mid;
    }
    printf("%lf\n",l);

    return 0;
}