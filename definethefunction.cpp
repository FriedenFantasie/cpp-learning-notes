#include<iostream>
using namespace std;

int sum(int a, int b) {
    return a + b; // 返回两个整数的和
}

int main() {
    int result;
    result = sum(5, 10);
    cout << "The sum is: " << result << endl;
    return 0;
}