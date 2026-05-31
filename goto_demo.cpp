#include <iostream>
#include <cstdlib>  // 用于system函数
#include <windows.h>
#include <fcntl.h>
#include <io.h>

/**
 * goto语句演示程序
 * 
 * 这个程序演示了goto语句的基本用法
 */
int main() {
    // 在运行前用system命令设置控制台编码
    system("chcp 936 > nul");  // 使用936(GBK)编码，适合中文Windows
    
    // 额外设置控制台代码页
    SetConsoleOutputCP(936);
    SetConsoleCP(936);
    
    // 使用_setmode设置stdout为二进制模式
    _setmode(_fileno(stdout), _O_BINARY);
    
    std::cout << "====== goto语句演示 ======\n\n";
    
    // 示例1：基本跳转
    std::cout << "【示例1】基本跳转\n";
    std::cout << "这行会被执行\n";
    
    goto label1;
    
    std::cout << "这行不会被执行\n";
    
label1:
    std::cout << "跳转到这里继续执行\n\n";
    
    
    // 示例2：跳出嵌套循环
    std::cout << "【示例2】使用goto跳出嵌套循环\n";
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            std::cout << "i=" << i << ", j=" << j;
            
            if (i == 2 && j == 2) {
                std::cout << " (找到目标位置，准备跳出所有循环)\n";
                goto outer;
            }
            
            std::cout << "\n";
        }
    }
    
outer:
    std::cout << "已跳出所有循环\n\n";
    
    
    // 示例3：错误处理
    std::cout << "【示例3】使用goto进行错误处理\n";
    
    bool step1 = true;
    bool step2 = false;  // 这步会失败
    bool step3 = true;
    
    if (!step1) {
        std::cout << "步骤1失败\n";
        goto cleanup;
    }
    
    std::cout << "步骤1成功\n";
    
    if (!step2) {
        std::cout << "步骤2失败\n";
        goto cleanup;
    }
    
    std::cout << "这一行不会执行，因为步骤2失败了\n";
    
    if (!step3) {
        std::cout << "步骤3失败\n";
        goto cleanup;
    }
    
cleanup:
    std::cout << "执行清理工作...\n\n";
    
    
    // 示例4：goto的替代方案
    std::cout << "【示例4】goto的替代方案\n";
    std::cout << "现代编程中，推荐使用以下方式代替goto:\n";
    std::cout << "- 结构化控制语句 (if/else, switch, 循环)\n";
    std::cout << "- 函数和提前返回\n";
    std::cout << "- 异常处理 (try/catch)\n\n";
    
    // 等待用户按任意键退出
    system("pause");
    return 0;
}
