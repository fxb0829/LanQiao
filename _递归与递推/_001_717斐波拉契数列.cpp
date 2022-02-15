/*
 * @Description: 
 * @Author: fengxb
 * @Date: 2022-02-15 09:57:56
 * @LastEditor: fengxb
 * @LastEditTime: 2022-02-15 11:08:16
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//斐波拉契数列--递归
int febo(int n){
    if(n == 0)return 0;
    if(n == 1)return 1;
    return febo(n-1)+febo(n-2);
}

int main(){
    int n;
    cin >> n;
    //递归版本
    // for(int i = 0; i < n; i++){
    //     cout << febo(i) << " ";
    // }

    //非递归版本
    int x = 0,y = 1;
    for (int i = 0; i < n; i++){
        if(i <= 1){
            cout << i << " ";
        }else{
            int temp = x+y;
            cout << temp << " ";
            x = y;
            y = temp;
        }
    }
    
    return 0;
}