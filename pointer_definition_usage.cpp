#include <iostream>

using namespace std;

int main()
{
    int number = 10;
    int* pointer = &number;

    cout << "变量 number 的值：" << number << endl;
    cout << "变量 number 的地址：" << &number << endl;
    cout << "指针 pointer 保存的地址：" << pointer << endl;
    cout << "通过指针访问 number 的值：" << *pointer << endl;

    *pointer = 20;

    cout << endl;
    cout << "通过指针修改后：" << endl;
    cout << "变量 number 的值：" << number << endl;
    cout << "通过指针访问 number 的值：" << *pointer << endl;

    return 0;
}
