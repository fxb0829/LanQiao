#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 100010;
int n;
int a[N],b[N],c[N];

int main(){
    //输入
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",&a[i]);
    for(int i = 0; i < n; i++) scanf("%d",&b[i]);
    for(int i = 0; i < n; i++) scanf("%d",&c[i]);

    //对A和C进行排序
    sort(a,a+n);
    sort(c,c+n);

    LL res = 0;
    for(int i = 0; i < n; i++){
        int ap = 0,cp = 0;
        int target = b[i];
        while(ap < n && a[ap] < target) ap++;
        while(cp < n && c[cp] <= target) cp++; 
        res += (LL)ap*(n-cp);
    }
    cout << res << endl;

    return 0;
}