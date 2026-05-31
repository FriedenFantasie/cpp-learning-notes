#include<iostream>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,5};    
    cout<<"逆置前的数组为："<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<" "; // 输出当前数组元素
    }
    int start = 0; // 记录起始索引
    int end = sizeof(arr)/sizeof(arr[0]) - 1; // 记录结束索引
    while(start < end) // 交换元素直到中间
    {
        int temp = arr[start]; // 暂存当前元素
        arr[start] = arr[end]; // 交换元素
        arr[end] = temp; // 交换元素
        start++; // 起始索引向后移动
        end--; // 结束索引向前移动
    }
    cout<<"逆置后的数组为："<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<" "; // 输出当前数组元素
    }
    //cout << endl;

    return 0;       
}