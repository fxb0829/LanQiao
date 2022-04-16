#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

string str;
int k;

int dfs(){
    int len = 0;
    while(k < str.size()){
        if(str[k] == '('){  //解决 (....)
            k++;  //跳过 (
            len += dfs();
            k++;  //跳过 )
        }
        else if(str[k] == '|'){
            k++; //跳过 |
            //左右两边取最大
            len = max(len,dfs());
        }else if(str[k] == ')') break;
        else{
            len++;  // x计数
            k++;    // 跳过 x
        }
    }
    return len;
}

int main(){
    cin >> str;

    cout << dfs() << endl;
    return 0;
}