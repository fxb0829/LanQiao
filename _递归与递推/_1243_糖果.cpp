#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 110,M = 1<<20;
int n,m,k;
vector<int> col[N];
int log2[M];

int lowbit(int x){
    return x & -x;
}

//计算当前状态至少还需要多少行
int h(int state){
    int res = 0;
    for(int i = (1<<m)-1-state; i; i -= lowbit(i)){
        int c = log2[lowbit(i)];
        res++;
        //从i中将每包糖果去除
        for(auto row: col[c]) i &= ~row;
    }
    return res;
}

bool dfs(int depth,int state){
    if(!depth || h(state) > depth) return state == (1<<m)-1;

    //找到选择性最少的一列
    int t = -1;
    //用m个1减去state,那么此时state二进制中的1就是还需要选择的
    // i -= lowbit(i),每次减掉i的最后一位1
    for(int i = (1<<m)-1-state; i; i -= lowbit(i)){
        //找到最后一位1的位置（log2数组中提前准备好二进制每个每一位的位置）
        int c = log2[lowbit(i)]; //c就是最后一位1所在数组的位置
        //t == -1还未选  找到哪一列包含的糖果包最少就选那一种类
        if(t == -1 || col[t].size() > col[c].size()) t = c;
    }

    //枚举哪一行
    for(auto row :col[t]){
        if(dfs(depth-1,state | row)) return true;
    }
    return false;
}

int main(){
    cin >> n >> m >> k;
    //预处理log2
    for(int i = 0; i < m; i++) log2[1<<i] = i;
    //读入每一行
    for(int i = 0; i < n; i++){
        //每行用一个数来表示（二进制）
        int state = 0;
        for(int j = 0; j < k; j++){
            int c;
            cin >> c;
            //比如c=2,只需左移一位，然后再与state相与
            state |= (1 << c-1); 
        }
        //枚举下每一列,看看这一包糖有哪些种类
        for(int j = 0; j < m; j++){
            //如果某一位是1，那么这包糖果就包含这一种类
            if(state >> j & 1) col[j].push_back(state);
        }
    }

    //去重(可能出现种类相同的糖果包)
    for (int i = 0; i < m; i ++ ){
        sort(col[i].begin(), col[i].end());
        col[i].erase(unique(col[i].begin(), col[i].end()), col[i].end());
    }

    //迭代加深
    int depth = 0;
    while(depth <= m && !dfs(depth,0)) depth++;

    //层数大于糖果的包数，返回-1
    if(depth > m) depth = -1;
    cout << depth << endl;

    return 0;
}