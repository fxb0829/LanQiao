#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

const int N = 10010;
int n;
int a[N];

int main(){
    //读入个数
    int cnt;
    cin >> cnt;
    string line;
    getline(cin,line); //忽略第一行的回车
    
    //读入每一行的数
    while(cnt--){
        getline(cin,line);
        stringstream ss(line);
        while(ss >> a[n]) n++;
    }

    //排序
    sort(a,a+n);

    //寻找
    int res1,res2;
    for(int i = 1; i < n; i++){ 
        if(a[i] == a[i-1]) res2 = a[i];
        else if(a[i] > a[i-1]+1) res1 = a[i]-1;
    }
    cout << res1 << ' ' << res2 << endl;

    return 0;
}