#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int main(){
    int x,y; 
    cin >> x >> y;
    if(abs(x) <= y){  //上方
        int n = y;
        cout << (LL)(2*n-1)*(2*n)+x-(-n) << endl;
    }else if(abs(y) <= x){  //左右方
        int n = x;
        cout<<(LL)(2*n)*(2*n)+n-y << endl;
    }else if(abs(x) <= abs(y)+1){   //下方
        int n = abs(y);
        cout << (LL)(2*n)*(2*n+1) + n-x << endl;
    }else{  //左方
        int n = abs(x);
        cout << (LL)(2*n-1)*(2*n-1)+y-(-n) << endl;
    }

    return 0;
}
