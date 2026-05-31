#include<iostream>
using namespace std;

#define MAX 7
const int days = 7; // 常量定义
// days = 10;  // 这行代码会导致编译错误，因为 days 是一个常量
int main()
{
   system("pause");
   cout<<"一周总共有"<<days<<"天"<<endl;
   return 0;
}