#include <iostream>

using namespace std;

int main()
{
    for (int row = 1; row <= 9; row++) {
        for (int space = 0; space < row - 1; space++) {
            cout << "\t";
        }

        for (int col = row; col <= 9; col++) {
            cout << row << "x" << col << "=" << row * col << "\t";
        }

        cout << endl;
    }

    return 0;
}
