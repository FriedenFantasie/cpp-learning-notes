#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 20;

    cout << "1. 常量指针：const int* p1" << endl;
    const int* p1 = &a;

    cout << "*p1 = " << *p1 << endl;
    p1 = &b;
    cout << "p1 指向 b 后，*p1 = " << *p1 << endl;

    // *p1 = 100; // 错误：常量指针不能通过指针修改指向的值

    cout << endl;
    cout << "2. 指针常量：int* const p2" << endl;
    int* const p2 = &a;

    cout << "*p2 = " << *p2 << endl;
    *p2 = 100;
    cout << "通过 p2 修改 a 后，a = " << a << endl;

    // p2 = &b; // 错误：指针常量不能修改指针保存的地址

    cout << endl;
    cout << "3. const 同时修饰指针和值：const int* const p3" << endl;
    const int* const p3 = &a;

    cout << "*p3 = " << *p3 << endl;

    // *p3 = 200; // 错误：不能通过 p3 修改指向的值
    // p3 = &b;   // 错误：不能修改 p3 保存的地址

    cout << endl;
    cout << "4. 指向常量的指针" << endl;
    const int c = 30;
    const int* p4 = &c;

    cout << "常量 c = " << c << endl;
    cout << "通过 p4 访问 c，*p4 = " << *p4 << endl;

    // *p4 = 300; // 错误：c 是常量，不能通过指针修改

    return 0;
}
