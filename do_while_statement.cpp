#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    //char choice = 'y';

    do {
        cout << "请输入一个整数：";
        cin >> number;

        if (!cin) {
            cout << "输入错误，请输入整数。" << endl;
            return 1;
        }

        cout << "你输入的数字是：" << number << endl;
        cout << "是否继续输入？(y/n)：";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "程序结束。" << endl;

    return 0;
}
