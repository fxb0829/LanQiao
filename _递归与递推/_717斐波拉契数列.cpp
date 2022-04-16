/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-15 09:57:56
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-17 12:23:11
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int x = 0,y = 1;
    for (int i = 1; i <= n; i++)
    {
        cout << x << " ";
        int tmp = x + y;
        x = y;
        y = tmp;
    }
    
    return 0;
}