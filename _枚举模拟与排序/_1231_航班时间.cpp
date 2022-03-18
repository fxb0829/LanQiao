#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int get_seconds(int h,int m,int s){
    return h*3600 + m * 60 + s;
}

int get_time(){
    string line;
    getline(cin,line);
    if(line.back() != ')') line += "(+0)";

    int h1,m1,s1,h2,m2,s2,d;
    //sscanf(str,"格式",&变量)  按照指定格式从str读取数据
    //line.c_str() 将line的数据转换为字符串
    sscanf(line.c_str(),"%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&d);
    
    //返回时间
    return get_seconds(h2,m2,s2) - get_seconds(h1,m1,s1) + d*24*3600;
}

int main(){
    int n;
    scanf("%d",&n);
    string line;      
    getline(cin,line);  //忽略第一行的回车(scanf不会读入最后那个回车)
    while(n--){
        int time = (get_time() + get_time()) /2;
        int hour = time / 3600;
        int minute = time % 3600 / 60;
        int second = time % 60;
        printf("%02d:%02d:%02d\n",hour,minute,second);
    }

    return 0;
}