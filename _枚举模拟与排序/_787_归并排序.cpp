#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1000010;
int n;
int q[N],tmp[N];

void merge_sort(int q[],int l,int r){
    if(l >= r) return ;

    int mid = l + r >> 1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);

    //合并
    int k = 0,i = l, j = mid+1; //合并的个数，两个序列的左端点
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    //将循环剩下的部分进行处理
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];

    //将tmp结果复制到q中
    for(int i = l,j = 0; i <= r; i++,j++){
        q[i] = tmp[j];
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",&q[i]);

    //归并排序
    merge_sort(q,0,n-1);

    //输出
    for(int i = 0; i < n; i++){
        printf("%d ",q[i]);
    }

    return 0;
}