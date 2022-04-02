#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n ;i++) scanf("%d",&a[i]);

    int res = 0;
    for(int i = 1; i < n; i++){
        if(a[i]-a[i-1] > 0) res += a[i]-a[i-1];
    }

    cout << res << endl;
    return 0;
}