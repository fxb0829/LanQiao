#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int res = n;
    while (n >= 3){
        int temp = n / 3;
        res += temp;
        n = temp + n % 3;
    }
    cout << res << endl;
    return 0;
}