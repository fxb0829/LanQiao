#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010;
int n;
struct Edge{
    int id,w;
};
vector<Edge> h[N];
int dist[N];

void dfs(int u,int father,int distance){
    //当前节点的距离
    dist[u] = distance;

    for(auto node:h[u]){
        if(node.id != father){
            dfs(node.id,u,distance+node.w);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n-1; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        h[a].push_back({b,c});
        h[b].push_back({a,c});
    }

    dfs(1,-1,0);

    //找到距离1号点最远的点
    int u = 1;
    for(int i = 1; i <= n; i++){
        if(dist[i] > dist[u]) u = i;
    }
    //再从u遍历一遍
    dfs(u,-1,0);
    for(int i = 1; i <= n; i++){
        if(dist[i] > dist[u]) u = i;
    }
    
    //费用计算
    int s = dist[u];
    printf("%lld\n",s*10+s*(s+1ll)/2);

    return 0;
}

