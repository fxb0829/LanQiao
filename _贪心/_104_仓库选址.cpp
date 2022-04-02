#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d",&a[i]);

    sort(a,a+n);
    
    int mid = n >> 1;
    int res = 0;
    for(int i = 0; i < n; i++){
        res += abs(a[i]-a[mid]);
    }
    printf("%d\n",res);
    return 0;
}