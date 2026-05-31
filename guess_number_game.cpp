#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int target = rand() % 100 + 1;
    int guess = 0;
    int count = 0;

    cout << "猜数字游戏开始！" << endl;
    cout << "我已经想好了一个 1 到 100 之间的整数。" << endl;

    while (guess != target) {
        cout << "请输入你猜的数字：";
        cin >> guess;

        if (!cin) {
            cout << "输入错误，请输入整数。" << endl;
            return 1;
        }

        count++;

        if (guess > target) {
            cout << "猜大了，再试一次。" << endl;
        } else if (guess < target) {
            cout << "猜小了，再试一次。" << endl;
        } else {
            cout << "恭喜你，猜对了！" << endl;
            cout << "你一共猜了 " << count << " 次。" << endl;
        }
    }

    return 0;
}
