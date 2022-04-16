#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

LL exgcd(LL a,LL b,LL &x,LL &y){
    if(b == 0){
        x = 1,y = 0;
        return a;
    }

    int d = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}

int main(){
    LL a,b,c,k;
    while(cin >> a >> b >> c >> k, a||b||c||k){
        LL x,y;
        LL z = 1ll << k;
        LL d = exgcd(c,z,x,y);
        if((b-a) % d) cout << "FOREVER" << endl; 
        else{
            x *= (b-a)/d;
            z /= d;
            cout << ((x % z)+z)%z << endl;
        }
    }
    return 0;
}