#include<iostream>
using namespace std;

int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 定义一个整数数组
//const int size = sizeof(arr) / sizeof(arr[0]); // 计算数组的大小
int arr1[10];
int main() {
    cout << "原数组: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " "; // 输出原数组
    }
    cout << endl;

    // 反转数组
    for (int i = 0; i < 10; i++) {
        //int temp = arr[i]; // 临时变量存储当前元素
        //arr[i] = arr[10 - 1 - i]; // 将对称位置的元素赋值给当前元素
        //arr[10 - 1 - i] = temp; // 将临时变量的值赋值给对称位置的元素
        arr1[i] = arr[10 - 1 - i];
    }

    cout << "反转后的数组: ";
    for (int i = 0; i < 10; i++) {
        cout << arr1[i] << " "; // 输出反转后的数组
    }
    cout << endl;

    return 0;
}