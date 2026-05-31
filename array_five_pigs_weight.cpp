#include <iostream>

using namespace std;

int main()
{
    double weights[5] = {0};
    double maxWeight = 0;

    cout << "请输入 5 只小猪的体重：" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "第 " << i + 1 << " 只小猪的体重：";
        cin >> weights[i];

        if (!cin) {
            cout << "输入错误，请输入数字。" << endl;
            return 1;
        }
    }
    int maxIndex = 0;
    maxWeight = weights[0];

    for (int i = 1; i < 5; i++) {
        if (weights[i] > maxWeight) 
        {
            maxWeight = weights[i];

            maxIndex = i+1;
        }
    }

    cout << "最重的小猪体重是：" << maxWeight << endl;
    cout << "最重的小猪编号是："<<maxIndex<<endl;

    /*for (int i = 0; i < 5; i++) {
        if (weights[i] == maxWeight) {
            cout << i + 1 << " ";
        }
    }

    cout << endl;

    return 0;*/
}
