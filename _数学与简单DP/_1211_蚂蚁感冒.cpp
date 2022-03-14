#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 55;
int n;
int my[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> my[i];
    }
    //记录左边向右走的蚂蚁数量，右边向左走的蚂蚁数量
    int left = 0, right = 0;
    for(int i = 1; i < n; i++){
        if(abs(my[i]) < abs(my[0]) && my[i] > 0) left++;
        else if(abs(my[i]) > abs(my[0]) && my[i] < 0) right++;
    }
    if(my[0] > 0 && right == 0 || my[0] < 0 && left == 0){ 
        //没有相遇的情况
        cout << 1 << endl;
    }else{
        //有相遇的情况，无论第一只蚂蚁走向哪边，都是一样的计算公式
        cout << left+right+1 << endl;
    }
    return 0;
}