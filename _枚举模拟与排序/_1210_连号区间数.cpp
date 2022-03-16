#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int n;
int a[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    for(int i = 0; i < n; i++){
        int Max = INT32_MIN;
        int Min = INT32_MAX;
        for(int j = i; j < n; j++){
            Min = min(Min,a[j]);
            Max = max(Max,a[j]);
            if(Max-Min == j-i) res++;
        }
    }
    cout << res << endl;

    return 0;
}