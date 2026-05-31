#include <iostream>
#include <string>

using namespace std;

int add(int num1, int num2)
{
    return num1 + num2;
}

int add(int num1, int num2, int num3)
{
    return num1 + num2 + num3;
}

double add(double num1, double num2)
{
    return num1 + num2;
}

string add(const string& str1, const string& str2)
{
    return str1 + str2;
}

void showInfo(int age)
{
    cout << "年龄：" << age << endl;
}

void showInfo(const string& name)
{
    cout << "姓名：" << name << endl;
}

void showInfo(const string& name, int age)
{
    cout << "姓名：" << name << "，年龄：" << age << endl;
}

int main()
{
    cout << "1. 参数个数不同，可以构成函数重载" << endl;
    cout << "add(10, 20) = " << add(10, 20) << endl;
    cout << "add(10, 20, 30) = " << add(10, 20, 30) << endl;

    cout << endl;
    cout << "2. 参数类型不同，可以构成函数重载" << endl;
    cout << "add(1.5, 2.6) = " << add(1.5, 2.6) << endl;
    cout << "add(string(\"Hello, \"), string(\"C++\")) = "
         << add(string("Hello, "), string("C++")) << endl;

    cout << endl;
    cout << "3. 同名函数 showInfo，根据传入参数自动调用对应版本" << endl;
    showInfo(18);
    showInfo("Zhang San");
    showInfo("Li Si", 20);

    // 注意：函数重载只看参数列表，不能只靠返回值类型不同来重载。
    // int test();
    // double test(); // 错误：参数列表相同，只有返回值不同，不能构成重载

    return 0;
}
