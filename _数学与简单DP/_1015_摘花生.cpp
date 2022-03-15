#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
int n,m;
int w[N][N];

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> w[i][j];
            }
        }
        int f[N] = {0};
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=m; j++){
                f[j] = max(f[j-1],f[j])+w[i][j];
            }
        }
        cout << f[m] << endl;
    }
    return 0;
}