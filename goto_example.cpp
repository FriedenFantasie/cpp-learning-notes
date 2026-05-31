#include <iostream>
#include <string>
#include <windows.h>
#include <locale>

/**
 * 演示goto语句的作用与用法
 * 
 * goto语句允许无条件跳转到程序内的标记位置(label)
 * 虽然在现代编程中不鼓励使用goto，但了解它的工作原理仍然很有价值
 */
int main() {
    // 设置控制台为UTF-8编码，以正确显示中文
    SetConsoleOutputCP(936);  // 使用936(GBK)编码，在中文Windows上更可靠
    // 设置本地化
    setlocale(LC_ALL, "");
    
    std::cout << "===== goto语句示例 =====" << std::endl << std::endl;
    
    // 示例1: 简单的无条件跳转
    std::cout << "示例1: 简单的无条件跳转" << std::endl;
    std::cout << "这是第一条语句" << std::endl;
    
    goto example1_label;
    
    std::cout << "这一行不会被执行" << std::endl;
    
example1_label:
    std::cout << "跳转到这里后继续执行" << std::endl << std::endl;
    
    
    // 示例2: 在循环中使用goto跳出多层嵌套
    std::cout << "示例2: 使用goto跳出多层嵌套循环" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "i = " << i << ", j = " << j;
            
            // 当i=1且j=1时，直接跳出所有循环
            if (i == 1 && j == 1) {
                std::cout << " (触发跳转条件!)" << std::endl;
                goto exit_nested_loops;
            }
            
            std::cout << std::endl;
        }
    }
    
exit_nested_loops:
    std::cout << "已跳出所有嵌套循环" << std::endl << std::endl;
    
    
    // 示例3: 使用goto实现错误处理
    std::cout << "示例3: 使用goto进行错误处理" << std::endl;
    
    // 假设这些是可能失败的操作
    bool operation1_success = true;
    bool operation2_success = false; // 这个操作将失败
    bool operation3_success = true;
    
    // 执行操作1
    if (!operation1_success) {
        std::cout << "操作1失败" << std::endl;
        goto cleanup;
    }
    std::cout << "操作1成功" << std::endl;
    
    // 执行操作2
    if (!operation2_success) {
        std::cout << "操作2失败" << std::endl;
        goto cleanup;
    }
    std::cout << "这一行不会被执行，因为操作2失败了" << std::endl;
    
    // 执行操作3 - 由于操作2失败，这里不会被执行
    if (!operation3_success) {
        std::cout << "操作3失败" << std::endl;
        goto cleanup;
    }
    std::cout << "操作3成功" << std::endl;
    
cleanup:
    std::cout << "执行清理操作..." << std::endl << std::endl;
    
    
    // 示例4: goto的替代方案 - 使用函数和返回值
    std::cout << "示例4: 现代编程中的替代方案" << std::endl;
    std::cout << "在现代C++中，通常建议使用以下方式代替goto:" << std::endl;
    std::cout << "- 结构化控制语句 (if/else, switch, 循环)" << std::endl;
    std::cout << "- 函数和提前返回" << std::endl;
    std::cout << "- 异常处理 (try/catch)" << std::endl << std::endl;
      std::cout << "按下回车键退出...";
    
    // 等待用户输入，确保能看到输出结果
    std::cin.get();
    
    // 在Windows命令行中可以使用system("pause")作为备选方案
    // system("pause");
    
    return 0;
}
