#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = (2<<20)+10;
int primes[N];  //质因子数组
int minp[N];    //每个数的最小质因子
bool st[N];

int get_primes(int n){
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(!st[i]) minp[i] = i,primes[cnt++] = i;
        for(int j = 0; primes[j]*i <= n; j++){
            st[primes[j]*i]  =true;
            minp[primes[j]*i] = primes[j];
            if(i % primes[j] == 0) break;
        }
    }
    return cnt;
}

int main(){
    
    get_primes(N-1);
    
    int fact[30],sum[N];
    int x;
    while(scanf("%d",&x) != -1){
        int k = 0,total = 0;
        while(x > 1){
            //最小质因子
            int p = minp[x];
            fact[k] = p,sum[k] = 0;
            while(x % p == 0){
                x /= p;
                sum[k]++;
                total++;
            }
            k++;
        }

        LL res = 1;
        //total的阶乘
        for(int i = 1; i <= total; i++) res *= i; 
        //除以每个质因子的阶乘
        for(int i = 0; i < k; i++){
            for(int j = 1; j <= sum[i]; j++){
                res /= j;
            }
        }
        printf("%d %lld\n",total,res);
    }

    return 0;
}