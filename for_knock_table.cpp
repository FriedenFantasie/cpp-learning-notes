#include <iostream>

using namespace std;

int main()
{
    for (int number = 1; number <= 100; number++) {
        if (number % 7 == 0 || number % 10 == 7 || number / 10 == 7) {
            cout << "敲桌子" << endl;
        } else {
            cout << number << endl;
        }
    }

    return 0;
}
