# STL基本使用

## C标准库常用函数

1. `<cstring>`

|`strlen()`|字符串长度|
| :-----: | ----- |
|`strcmp()`|字符串比较|
|`strcpy()`|字符串拷贝|
|`memset()`|暴力清空|
|`memcpy()`|暴力拷贝|

```cpp
char str[100];
...
memset(str,0,sizeof(str));  //str字符数组全部置为0
```

2. `<cmath>`

三角函数、指数函数、浮点取整函数

3. `<sdtdlib>`

|`qsort()`|c语言快排|
| ----- | ----- |
|`rand()`|随机数|
|`malloc() free()`|c语言动态分配内存|

4. `<ctime>`

|`time(0)`|从1970年到现在的秒数（配合随机数）|
| ----- | ----- |
|`clock()`|程序启动到目前位置的毫秒数|

5. `<cctype>`

|`isdigit()`|判断字符是否为数字|
| ----- | ----- |
|`isalpha()`|判断字符是否为大小写字母|

## STL-<vector>

`vector`可以看成一个“超级数组”

1. 基本使用

```cpp
#include <vector>

//数组用法
vector<int> arr1(100);
int arr2[100];

//链表用法
vector<int> list;
list.push_back(1);
list.push_back(2);
list.push_back(3);

//遍历
 vector<int> list;
for(int i=0; i < 5; i++)
{
        int a;
        cin>>a;
        list.push_back(a);
    }
    for (int val:list)
    {
        cout << val << endl;
    }

//迭代器
vector<int> arr(100);
vector<int>::iterator p;
for(p = arr.begin(); p != arr.end(); p++)
{
    cout << *p << endl;
}
```

2. 常见操作

|`list.size()`|数组元素个数$O(1)$|
| ----- | ----- |
|`list.clear()`|清空数组$O(n)$|
|`list.empty()`|数组是否为空$O(1)$|
|`list.begin()`|数组的首元素迭代器$O(1)$|
|`list.end()`|该元素实际在数组中不存在|
|`list.erase()`|删除数组某个迭代器所在位置的数$O(n)$|
|`list.push_back()`|往数组添加元素$O(1)$|
|`list.pop_back()`|删除数组的最后一个元素$O(1)$|

### STL-<string>

1. 基本使用

```cpp
string str1 = "hello";
string str2;
str2.push_back("!");
```

2. 基本操作

|`str.length(), str.size()`|字符串长度$O(n)$|
| ----- | ----- |
|`str.insert(1,"aaa")`|在下标$1$的位置插入$O(n)$|
|`str.insert(str.begin(),'a')`|在迭代器处插入一个字符$O(n)$|
|`str.c_str()`|返回c语言字符串$O(n)$|
|`str.append(str2)`|把$str2$拼接大$str$后面$O(n)$|
|`str.compare(str2)`|`strcmp(str,str2)`|
|`str == str2`|`strcmp(str,str2)==0`|
|`str += str2`|`str.append(str2)`|
|`str += 'a'`|`str.push_back('a')`|

## STL-<algorithm>

包含大量的算法

1. sort快速排序

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //普通数组
    int arr[]{-1,3,5,67,23,56,23,88,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    for(int i = 0; i < n; i++){
        cout << "普通数组：" << arr[i] << endl;
    }
    
    //vector数组
    vector<int> arr2 = {-1,3,5,67,23,56,23,88,12};
    sort(arr2.begin(),arr2.end());
    for(int val:arr2){
        cout <<"vector数组："<< val << endl;
    }
    //自定义排序规则
    //sort(arr2.begin(),arr2.end(),cmpt);
    return 0;
}
```

2. 最大最小值

```cpp
max(1,2);
min(1,2);
//数组最大最小指针
max_element(arr.begin(),arr.end());
min_element(arr.begin(),arr.end());
//把数组中第n小的数放到第n个位置
//类似快排
nth_element(arr.begin(),arr.begin()+n,arr.end()); //O(n)
```

3. 交换两个同类型变量

```cpp
swap(arr[0],arr[1]);
```

4. 翻转数组

```cpp
reverse(arr.begin(),arr.end());
```

5. 数组去重

```cpp
//假设数组已经排好序,返回去重后的数组长度
int newLength = unique(arr.begin(),arr.end()-arr.begin());
```

6. 二分查找

```cpp
//数组中查找1
//vector<int> arr = {-1,1,2,2,3,5};
bool isExist = binary_serach(arr.begin(),arr.end(),1); //true

//把一个数插入已经排序好的数组，应该插在什么位置？
//lower_bound()返回第一个插入的位置
//upper_bound()返回最后一个插入的位置
//vector<int> arr = {-1,1,2,2,3,5};
int firstLoc = lower_bound(arr.begin(),arr.end(),2)-arr.begin(); //2
int lastLoc = upper_bound(arr.begin(),arr.end(),2)-arr.begin(); //4
```

## STL-<stack>

```cpp
#include <stack>

stack<int> sta;
```

|`sta.push()`|入栈|
| ----- | ----- |
|`sta.topElement = sta.pop()`|栈顶元素|
|`sta.pop()`|出栈|
|`sta.empty()`|判空|
|`sta.size()`|大小|

## STL-<queue>

```cpp
#inclue <queue>

//普通队列
queue<int> que;

//优先级队列
priority_queue<int> pque;
```

|`que.push(1)`|入队|
| ----- | ----- |
|`int frontElement = que.front();`|队头|
|`que.pop()`|弹出|
|`que.empty()`|判空|
|`que.size()`|大小|
| | |
|`pque.push(1)`|入队|
|`int minElement = pque.top();`|队顶最小元素|
|`pque.pop()`|弹出|
|`pque.empty()`|判空|
|`pque.size()`|大小|

## STL-<set>

```cpp
#include <set>

set<int> st;  //元素不可重复
st.insert(1);
st.find(1);
st.erase(1);

multiset<int> mst; //元素可以重复
mst.insert(1);
mst.insert(1);
mst.count(1);  //2
```

##  STL-<map>(映射)

```cpp
#include <map>

//pair --自带比较函数
pair<int,int> origin;
origin = make_pair(0,0);
origin.first == origin.second;
origin.swap; //返回swap新的pair

pair<string,int> id;
id = make_pair("somebody",110);

pair<string,int> pr("hello",120）;

//map
map<string,int> height;
pair<string,int> id("someone",160);
height["夏明"] = 180;
height["tony"] = 170;
height.insert(pair);  //插入pair
height.erase("tony"); //删除
```

## 精简头文件

用一个头文件包含上述的头文件

```cpp
#include <bits/stdc++.h>    //vs没有
```
