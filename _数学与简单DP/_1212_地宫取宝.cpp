#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 55,MOD = 1000000007;
int n,m,k;
int w[N][N];
int f[N][N][13][14];  //价值是从-1到12,共14个

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> w[i][j];
            w[i][j]++;
        }
    }
    //初始化
    f[1][1][1][w[1][1]] = 1;
    f[1][1][0][0] = 1;    //因为吗，每个价值都在读入的时候+1，所以这里为0，不是-1
    //状态计算
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1 && j == 1) continue;
            for(int u = 0; u <= k; u++){
                for(int v = 0; v <=13; v++){
                    int &val = f[i][j][u][v];
                    //不取的情况 方案数之和
                    val = (val+f[i-1][j][u][v]) % MOD;
                    val = (val+f[i][j-1][u][v]) % MOD;
                    //要取的情况 方案数之和
                    //取当前的这个说明当前这个的价值是目前取的当中价值最大的
                    //最大就自然要满足v == w[i][j]
                    if(u > 0 && v == w[i][j]){
                        for(int c = 0; c < v; c++){
                            val = (val + f[i-1][j][u-1][c]) % MOD;
                            val = (val + f[i][j-1][u-1][c]) % MOD;
                        }
                    }
                }
            }
        }
    }
    //求取最后的方案数之和
    int res = 0;
    for(int i = 0; i <= 13; i++){
        res = (res + f[n][m][k][i]) % MOD;
    }
    cout << res << endl;


    return 0;
}

