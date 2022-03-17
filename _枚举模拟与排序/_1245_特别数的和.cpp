#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int res = 0;
    for(int i = 1; i <= n; i++){
        //判断每个数是否含有2、0、1、9其中一个
        int x = i;
        while(x > 0){
            int t = x % 10;
            x = x / 10;
            if(t == 2 || t == 0 || t == 1 || t == 9){
                res += i;
                break;
            }
        }
    }
    cout << res << endl;

    return 0;
}