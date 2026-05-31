#include <iostream>

using namespace std;

class Person
{
public:
    Person()
    {
        age = 0;
        cout << "无参构造函数调用" << endl;
    }

    Person(int a)
    {
        age = a;
        cout << "有参构造函数调用" << endl;
    }

    Person(const Person& person)
    {
        age = person.age;
        cout << "拷贝构造函数调用" << endl;
    }

    void showPerson()
    {
        cout << "年龄：" << age << endl;
    }

private:
    int age;
};

void doWork(Person person)
{
    cout << "值传递进入函数" << endl;
    person.showPerson();
}

Person doWork2(bool flag)
{
    Person p1(30);
    Person p2(40);

    cout << "准备以值方式返回局部对象" << endl;

    if (flag)
    {
        return p1;
    }

    return p2;
}

void test01()
{
    cout << "----- 1. 使用一个已经创建完毕的对象初始化一个新对象 -----" << endl;

    Person p1(20);
    Person p2(p1);

    p2.showPerson();
}

void test02()
{
    cout << "----- 2. 值传递的方式给函数参数传值 -----" << endl;

    Person p1(25);
    doWork(p1);
}

void test03()
{
    cout << "----- 3. 以值方式返回局部对象 -----" << endl;

    Person p1 = doWork2(false);
    p1.showPerson();
}

int main()
{
    test01();
    cout << endl;

    test02();
    cout << endl;

    test03();

    return 0;
}
