#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 300010;
int n;
LL a[N],s[N];
bool st[N];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        s[0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%lld",&a[i]);
            s[i] = s[i-1]+a[i];
        }

        LL s0 = s[0],sn = s[n];
        if(s0 > sn) swap(s0,sn);
        sort(s,s+n+1);

        //找到s0与sn的位置
        for(int i = 0; i <= n; i++){
            if(s[i] == s0){
                s0 = i;
                break;
            }
        }
        for(int i = n; i >= 0; i--){
            if(s[i] == sn){
                sn = i;
                break;
            }
        }

        memset(st,0,sizeof st);
        int l = 0,r = n;
        for(int i = s0; i >= 0; i -= 2){
            a[l++] = s[i];
            st[i] = true;
        }
        for(int i = sn; i <= n; i += 2){
            a[r--] = s[i];
            st[i] = true;
        }
        for(int i = 0; i <= n; i++){
            if(!st[i]) a[l++] = s[i];
        }

        LL res = 0;
        for(int i = 1; i <= n; i++){
            res = max(res,abs(a[i]-a[i-1]));
        }

        printf("%lld\n",res);
    }
    return 0;
}
