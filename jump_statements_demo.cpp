#include <iostream> // 引入输入输出头文件，用来使用 cout 和 endl

using namespace std; // 使用标准命名空间，后面可以直接写 cout

int main() // 程序主函数，从这里开始执行
{ // main 函数开始
    cout << "break 结构演示：" << endl; // 输出 break 演示标题

    for (int i = 1; i <= 5; i++) { // for 循环，让 i 从 1 增加到 5
        if (i == 4) { // 判断 i 是否等于 4
            break; // 如果 i 等于 4，立刻跳出整个 for 循环
        } // if 判断结束

        cout << "i = " << i << endl; // 输出当前 i 的值
    } // break 示例的 for 循环结束

    cout << endl; // 输出空行，让结果更清楚
    cout << "continue 结构演示：" << endl; // 输出 continue 演示标题

    for (int j = 1; j <= 5; j++) { // for 循环，让 j 从 1 增加到 5
        if (j == 3) { // 判断 j 是否等于 3
            continue; // 如果 j 等于 3，跳过本次循环剩下的代码，直接进入下一次循环
        } // if 判断结束

        cout << "j = " << j << endl; // 输出当前 j 的值
    } // continue 示例的 for 循环结束

    cout << endl; // 输出空行，让结果更清楚
    cout << "goto 结构演示：" << endl; // 输出 goto 演示标题

    int k = 1; // 定义变量 k，并赋值为 1

start: // 定义一个标签，goto 可以跳转到这个位置
    cout << "k = " << k << endl; // 输出当前 k 的值
    k++; // 让 k 自增 1

    if (k <= 3) { // 判断 k 是否小于等于 3
        goto start; // 如果条件成立，就跳转回 start 标签处继续执行
    } // if 判断结束

    cout << endl; // 输出空行，让结果更清楚
    cout << "程序结束。" << endl; // 输出程序结束提示

    return 0; // 返回 0，表示程序正常结束
} // main 函数结束
