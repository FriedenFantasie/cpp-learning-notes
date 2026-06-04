#include <iostream>
#include <string>

class Student {
public:
    Student(std::string name, int age)
    {
        // 左边 this->name 是“当前对象的成员变量 name”。
        // 右边 name 是“传进来的形参 name”。
        this->name = name;
        this->age = age;
    }

    void rename(std::string name)
    {
        // 如果形参和成员变量同名，直接写 name 会优先表示形参。
        // 所以用 this->name 明确表示成员变量。
        this->name = name;
    }

    Student& growUp()
    {
        this->age++;

        // this 是当前对象的地址，类型是 Student*
        // *this 是当前对象本身，类型是 Student
        // 返回 Student& 可以让函数连续调用。
        return *this;
    }

    void printAddress() const
    {
        std::cout << "name: " << this->name << '\n';
        std::cout << "this address: " << this << '\n';
    }

private:
    std::string name;
    int age = 0;
};

int main()
{
    Student first("Alice", 18);
    Student second("Bob", 20);

    std::cout << "first object address: " << &first << '\n';
    first.printAddress();

    std::cout << "\nsecond object address: " << &second << '\n';
    second.printAddress();

    std::cout << "\nAfter chained calls:\n";
    first.rename("Cindy");
    first.growUp().growUp().printAddress();

    return 0;
}
