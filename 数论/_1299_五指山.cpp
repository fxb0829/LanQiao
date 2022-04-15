#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

LL exgcd(LL a,LL b,LL &x, LL &y){
    if(!b){
        x = 1,y = 0;
        return a;
    }

    LL d = exgcd(b,a%b,y,x);
    y -= a/b * x;
    return d;
}

int main(){
    // int T;
    // scanf("%d",&T);
    // while(T--){
    //     LL n,d,x,y,a,b;
    //     scanf("%lld%lld%lld%lld",&n,&d,&x,&y);

    //     int gcd = exgcd(n,d,a,b);
    //     if((y-x) % gcd) puts("Impossible");
    //     else{
    //         b *= (y-x) / gcd;
    //         n /= gcd;
    //         printf("%lld\n",(b % n + n)%n);
    //     }
    // }
    LL a,b;
    cout << exgcd(10,6,a,b) << endl;
    cout << a << " " << b << endl;
    return 0;
}