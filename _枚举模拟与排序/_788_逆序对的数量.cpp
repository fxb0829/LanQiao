#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long LL;

const int N = 1000010;
stack<int> mstack,tmp;
int n;
int a[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    LL res = 0;
    for(int i = 0; i < n; i++){
        int value = a[i];
        if(!mstack.empty() && mstack.top() > value){
            while(!mstack.empty() && mstack.top() > value){
                tmp.push(mstack.top());
                res++;
                mstack.pop();
            }
        }
        mstack.push(value);
        while(!tmp.empty()){
            mstack.push(tmp.top());
            tmp.pop();
        }
    }
    cout << res << endl;

    return 0;
}
