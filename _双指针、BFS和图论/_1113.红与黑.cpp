#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 25;
int n,m;
char g[N][N];
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};

int dfs(int x,int y){
    int res = 1;  //当前格子可以搜
    g[x][y] = '#';
    for(int i = 0; i < 4; i++){
        int a = x+dx[i];
        int b = y+dy[i];
        if(a >= 0 && a < n && b >= 0 && b < m && g[a][b]=='.'){
            res += dfs(a,b);
        }
    }
    return res;
}

int main(){
    //有多组数据，直到读取到0为止
    while (cin >> m >> n,n||m){
        //读入每行字符
        for(int i = 0; i < n; i++) cin >> g[i];
        
        //找到人的位置
        int x,y;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == '@'){
                    x = i,y = j;
                }
            }
        }
        cout << dfs(x,y) << endl;
    }
}