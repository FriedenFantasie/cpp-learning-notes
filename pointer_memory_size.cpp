#include <iostream>

using namespace std;

int main()
{
    int number = 10;
    double score = 98.5;
    char letter = 'A';

    int* pNumber = &number;
    double* pScore = &score;
    char* pLetter = &letter;

    cout << "普通变量所占内存空间：" << endl;
    cout << "int number 占用：" << sizeof(number) << " 字节" << endl;
    cout << "double score 占用：" << sizeof(score) << " 字节" << endl;
    cout << "char letter 占用：" << sizeof(letter) << " 字节" << endl;

    cout << endl;
    cout << "指针变量所占内存空间：" << endl;
    cout << "int* pNumber 占用：" << sizeof(pNumber) << " 字节" << endl;
    cout << "double* pScore 占用：" << sizeof(pScore) << " 字节" << endl;
    cout << "char* pLetter 占用：" << sizeof(pLetter) << " 字节" << endl;

    cout << endl;
    cout << "说明：在同一台电脑、同一个程序中，不同类型的指针大小通常相同。" << endl;

    return 0;
}
