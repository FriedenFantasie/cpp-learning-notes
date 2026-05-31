#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int i = 1;
    int sum = 0;

    cout << "请输入一个正整数：";
    cin >> n;

    if (!cin || n <= 0) {
        cout << "输入错误，请输入正整数。" << endl;
        return 1;
    }

    while (i <= n) {
        sum += i;
        i++;
    }

    cout << "从 1 加到 " << n << " 的结果是：" << sum << endl;

    return 0;
}
