#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 2000010;
int A,B,C,m;
LL s[N],b[N],bp[N];
int op[N/2][7]; //操作矩阵

//坐标偏移量
int d[8][4] = {
    {0,0,0,1},
    {0,0,1,-1},
    {0,1,0,-1},
    {0,1,1,1},
    {1,0,0,-1},
    {1,0,1,1},
    {1,1,0,1},
    {1,1,1,-1},
};

//坐标映射
int get(int x,int y,int k){
    return (x * B + y)*C + k;
}

bool check(int mid){
    //拷贝差分数组
    memcpy(b,bp,sizeof b);
    for(int i = 1; i <= mid; i++){
        //拿到操作的矩阵坐标
        int x1 = op[i][0],x2 = op[i][1];
        int y1 = op[i][2],y2 = op[i][3];
        int z1 = op[i][4],z2 = op[i][5];
        int h = op[i][6];
        //操作差分数组
        b[get(x1,   y1,   z1)]   -= h;
        b[get(x1,   y1,   z2+1)] += h;
        b[get(x1,   y2+1, z1)]   += h;
        b[get(x1,   y2+1, z2+1)] -= h;
        b[get(x2+1, y1,   z1)]   += h;
        b[get(x2+1, y1,   z2+1)] -= h;
        b[get(x2+1, y2+1, z1)]   -= h;
        b[get(x2+1, y2+1, z2+1)] += h;
    }

    memset(s,0,sizeof s);
    //修改区域数据后，更新数组
    //差分数组的前缀和就是计算那个位置的修改变化后的数
    for(int i = 1; i <= A; i++){
        for(int j = 1; j <= B ;j++){
            for(int k = 1; k <= C; k++){
                int index = get(i,j,k);
                s[index] = b[index];
                //后面7项
                for(int u = 1; u < 8; u++){
                    int x = i-d[u][0],y = j-d[u][1],z = k-d[u][2],t = d[u][3];
                    s[index] -= s[get(x,y,z)]*t;
                }
                if(s[index] < 0) return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d%d%d",&A,&B,&C,&m);
    for(int i = 1; i <= A; i++){
        for(int j = 1; j <= B; j++){
            for(int k = 1; k <= C; k++){
                //由于不知道ABC各自的范围，所有转换成一维数组，需要映射
                scanf("%lld",&s[get(i,j,k)]);
            }
        }
    }

    //计算三维矩阵的差分数组
    for(int i = 1; i <= A; i++){
        for(int j = 1; j<= B; j++){
            for(int k = 1; k <= C; k++){
                //8个方向
                for(int u = 0; u < 8; u++){
                    int x = i-d[u][0],y = j-d[u][1],z = k-d[u][2],t = d[u][3];
                    //使用备份差分数组，因为后面进行二分，需要多次使用差分数组
                    bp[get(i,j,k)] += s[get(x,y,z)]*t;
                }
            }
        }
    }

    //执行m个操作
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < 7; j++){
            scanf("%d",&op[i][j]);
        }
    }

    //二分查找
    int l = 1,r = m;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%d\n",r);

    return 0;
}