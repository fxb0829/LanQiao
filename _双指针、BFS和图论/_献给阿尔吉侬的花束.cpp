#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;

const int N = 210;
int n,m;
char g[N][N];
int dist[N][N];

//四个方向偏移量
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};

int bfs(PII start,PII end){
    queue<PII> q;
    //初始化距离矩阵
    memset(dist,-1,sizeof dist);
    //起始点距离为0
    dist[start.x][start.y] = 0;
    //将起始点放入队列
    q.push(start);
    while(q.size()){
        auto t = q.front();  //读取队列头部元素
        q.pop();             //弹出队头
        //判断是否到达终点(出队判断)
        //if(t == end) return dist[end.x][end.y];

        //循环四个方向
        for(int i = 0; i < 4; i++){
            int x = t.x+dx[i],y = t.y+dy[i];
            //判断是否出边界
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(g[x][y] == '#') continue; //障碍物
            if(dist[x][y] != -1) continue; //之前已经遍历过

            dist[x][y] = dist[t.x][t.y] + 1; //更新距离
            //加入队列
            //判断是否到达终点(入队判断)
            if(end == make_pair(x,y)) return dist[x][y];
            q.push({x,y});
        }
    }
    return -1;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++){
            //读入字符串
            scanf("%s",g[i]);
        }

        //起点终点
        PII start,end;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 'S') start = {i,j};
                else if(g[i][j] == 'E') end = {i,j};
            }
        }
        int distance = bfs(start,end);
        if(distance == -1) puts("opp!");
        else printf("%d\n",distance);
    }
    return 0;
}
