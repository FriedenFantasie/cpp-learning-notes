#include <iostream>

using namespace std;

int main()
{
    int choice = 0;

    cout << "请选择要学习的内容：" << endl;
    cout << "1. C++ 输入输出" << endl;
    cout << "2. if 判断语句" << endl;
    cout << "3. switch 选择结构" << endl;
    cout << "4. for 循环语句" << endl;
    cout << "请输入选项编号：";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "你选择了：C++ 输入输出" << endl;
        break;
    case 2:
        cout << "你选择了：if 判断语句" << endl;
        break;
    case 3:
        cout << "你选择了：switch 选择结构" << endl;
        break;
    case 4:
        cout << "你选择了：for 循环语句" << endl;
        break;
    default:
        cout << "输入的选项不存在。" << endl;
        break;
    }

    return 0;
}
