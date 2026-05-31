#include<iostream>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6}; // 定义一个整数数组
    int n = sizeof(arr) / sizeof(arr[0]); // 计算数组的大小

    // 冒泡排序算法
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // 输出排序后的数组
    cout << "排序后的数组: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}