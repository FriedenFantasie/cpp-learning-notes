#include <iostream>

using namespace std;

class Person
{
public:
    Person(int a, int b, int c)
        : m_A(a), m_B(b), m_C(c)
    {
        cout << "构造函数初始化列表调用" << endl;
    }

    void showPerson()
    {
        cout << "m_A = " << m_A << endl;
        cout << "m_B = " << m_B << endl;
        cout << "m_C = " << m_C << endl;
    }

private:
    int m_A;
    int m_B;
    int m_C;
};

int main()
{
    Person person(10, 20, 30);
    person.showPerson();

    return 0;
}
