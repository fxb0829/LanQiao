#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int n,m;
int a[N],b[N];

//对差分数组的操作
void insert(int l,int r, int c){
    b[l] += c;
    b[r+1] -= c;
}

int main(){
    cin >> n >>m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    //假设原数组a为空，每次在i位置加上a[i]，就可以构建出差分数组
    //也可以遍历原始数组计算差分数组
    for(int i = 1; i <= n; i++) insert(i,i,a[i]);

    //计算完差分数组之后，后面开始处理m个操作
    while(m--){
        int l,r,c;
        cin >> l >> r >> c;
        insert(l,r,c);
    }
    
    //最后，使用原始数组加上差分数组就可以得到新的结果数组
    for(int i = 1; i <= n; i++){
        a[i] = a[i-1] + b[i];
    }
    
    for(int i = 1; i <= n; i++) cout<< a[i] << " ";
    puts("");

    return 0;
}