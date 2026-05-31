#include<iostream>
#include"swap.h"
using namespace std;

// swap函数的实现
void swap(int &a, int &b) {
    int temp = a; // 使用临时变量存储a的值
    a = b;        // 将b的值赋给a
    b = temp;    // 将临时变量的值赋给b
}