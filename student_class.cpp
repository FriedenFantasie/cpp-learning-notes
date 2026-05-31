#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    void setName(string n)
    {
        name = n;
    }

    void setStudentId(string id)
    {
        studentId = id;
    }

    void showStudent()
    {
        cout << "学生姓名：" << name << endl;
        cout << "学生学号：" << studentId << endl;
    }

private:
    string name;
    string studentId;
};

int main()
{
    Student student;

    student.setName("张三");
    student.setStudentId("2026001");
    student.showStudent();

    return 0;
}
