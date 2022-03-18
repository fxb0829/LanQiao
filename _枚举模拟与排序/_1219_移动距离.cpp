#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int w,m,n;
    cin >> w >> m >> n;
    m--,n--;
    
    int x1,y1,x2,y2;
    //行号
    x1 = m / w, x2 = n / w;
    //列号
    y1 = m % w, y2 = n % w;
    if((x1 & 1) == 1) y1 = w - y1 - 1;
    if((x2 & 1) == 1) y2 = w - y2 - 1;

    cout << abs(x1-x2)+abs(y1-y2) << endl;

    return 0;
}