#include<iostream>
using namespace std;
#include "swap.h"

int main() {
    int a = 10;
    int b = 20;
    cout << "交换前：a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "交换后：a = " << a << ", b = " << b << endl;
    return 0;
}   