#include <iostream>
#include <string>

using namespace std;

void printNumber(const int& number)
{
    cout << "函数中通过常量引用读取 number：" << number << endl;

    // number = 100; // 错误：常量引用不能修改绑定的变量
}

void printStudent(const string& name, const int& age)
{
    cout << "学生姓名：" << name << endl;
    cout << "学生年龄：" << age << endl;
}

int main()
{
    int a = 10;
    int& normalRef = a;
    const int& constRef = a;

    cout << "1. 普通引用可以修改变量" << endl;
    cout << "修改前 a = " << a << endl;
    normalRef = 20;
    cout << "通过普通引用修改后 a = " << a << endl;

    cout << endl;
    cout << "2. 常量引用只能读取变量" << endl;
    cout << "constRef = " << constRef << endl;

    // constRef = 30; // 错误：常量引用不能修改变量

    a = 30;
    cout << "直接修改 a 后，constRef = " << constRef << endl;

    cout << endl;
    cout << "3. 常量引用可以作为函数参数，避免拷贝并保护数据" << endl;
    printNumber(a);

    string name = "Zhang San";
    int age = 18;
    printStudent(name, age);

    cout << endl;
    cout << "4. 常量引用可以绑定临时值" << endl;
    const int& tempRef = 100;
    cout << "tempRef = " << tempRef << endl;

    return 0;
}
