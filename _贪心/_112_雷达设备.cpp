#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1010;

int n,d;
struct Segment{
    double l,r;
    bool operator < (const Segment & t) const{
        return r < t.r;
    }
}seg[N];

int main(){
    scanf("%d%d",&n,&d);
    bool failed = false;
    for(int i = 0; i < n; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(y > d) failed = true;  //高度高于d则不可能包含
        else{
            double len = sqrt(d*d-y*y);
            seg[i] = {x-len,x+len};
        }
    }
    if(failed){
        puts("-1");
    }else{
        //排序
        sort(seg,seg+n);

        int cnt = 0;
        double last = -1e20;
        for(int i = 0; i < n; i++){
            if(last < seg[i].l){
                cnt++;
                last = seg[i].r;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}