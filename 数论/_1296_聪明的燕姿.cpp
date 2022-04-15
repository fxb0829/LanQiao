#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 50000;
int primes[N],ans[N],len;
bool st[N];

int get_primes(int n){
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j]*i <= n; j++){
            st[primes[j]*i] = true;
            if(i % primes[j] == 0) break;
        }
    }
    return cnt;
}

bool is_prime(int x){
    //小于N说明在质因子的线性筛法的结果st中，可以直接判断
    if(x < N) return !st[x];

    for(int i = 0; primes[i] <= x/primes[i]; i++){
        if(x % primes[i] == 0) return false;
    }
    return true;
}

void dfs(int last,int prod,int s){
    if(s == 1){
        ans[len++] = prod;
        return;
    }
    
    //s = p+1的情况，判断s-1是不是质数
    if(s-1 > (last < 0 ? 1:primes[last]) && is_prime(s-1)){
        ans[len++] = prod * (s-1);
    }

    //继续枚举
    for(int i = last+1; primes[i] <= s/primes[i]; i++){
        int p = primes[i];
        for(int j = 1+p,t = p; j <= s; t *= p,j += t){
            if(s % j == 0) dfs(i,prod*t,s/j);
        }
    }
}

int main(){
    get_primes(N-1);

    int s;
    while (cin >> s){
        len = 0;
        dfs(-1,1,s);

        cout << len << endl;
        if(len){
            sort(ans,ans+len);
            for(int i = 0; i < len; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}