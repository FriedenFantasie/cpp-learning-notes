#include <iostream>

using namespace std;

int main()
{
    int number = 100;

    cout << "100 到 999 之间的水仙花数有：" << endl;

    do {
        int hundred = number / 100;
        int ten = number / 10 % 10;
        int single = number % 10;

        int sum = hundred * hundred * hundred
            + ten * ten * ten
            + single * single * single;

        if (sum == number) {
            cout << number << endl;
        }

        number++;
    } while (number <= 999);

    return 0;
}
