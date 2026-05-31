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

void testConstructorType()
{
    cout << "----- 构造函数分类 -----" << endl;

    Person p1;
    p1.showPerson();

    Person p2(18);
    p2.showPerson();

    Person p3(p2);
    p3.showPerson();
}

void testCallByParentheses()
{
    cout << "----- 括号法 -----" << endl;

    Person p1;
    Person p2(20);
    Person p3(p2);

    p1.showPerson();
    p2.showPerson();
    p3.showPerson();

    // 注意：不要写 Person p4();
    // 编译器会把 Person p4(); 当作函数声明，而不是创建对象。
}

void testCallByExplicit()
{
    cout << "----- 显示法 -----" << endl;

    Person p1 = Person();
    Person p2 = Person(30);
    Person p3 = Person(p2);

    p1.showPerson();
    p2.showPerson();
    p3.showPerson();

    // Person(40); 是匿名对象。
    // 当前这一行执行结束后，匿名对象就会被释放。
    Person(40);
}

void testCallByImplicitConversion()
{
    cout << "----- 隐式转换法 -----" << endl;

    Person p1 = 40;
    Person p2 = p1;

    p1.showPerson();
    p2.showPerson();
}

int main()
{
    testConstructorType();
    cout << endl;

    testCallByParentheses();
    cout << endl;

    testCallByExplicit();
    cout << endl;

    testCallByImplicitConversion();

    return 0;
}
