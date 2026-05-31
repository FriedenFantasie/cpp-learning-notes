#include <iostream>

using namespace std;

int main()
{
    double pig1 = 0.0;
    double pig2 = 0.0;
    double pig3 = 0.0;

    cout << "请输入三只小猪的体重，用空格隔开：";
    cin >> pig1 >> pig2 >> pig3;

    if (!cin) {
        cout << "输入错误，请输入数字。" << endl;
        return 1;
    }

    double maxWeight = pig1;

    if (pig2 > maxWeight) {
        maxWeight = pig2;
    }

    if (pig3 > maxWeight) {
        maxWeight = pig3;
    }

    cout << "最重的体重是：" << maxWeight << endl;
    cout << "最重的小猪编号：";

    if (pig1 == maxWeight) {
        cout << "1 ";
    }
    if (pig2 == maxWeight) {
        cout << "2 ";
    }
    if (pig3 == maxWeight) {
        cout << "3 ";
    }

    cout << endl;

    return 0;
}
