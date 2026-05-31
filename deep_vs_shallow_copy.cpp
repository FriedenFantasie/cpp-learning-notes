/*
 * ============================================================
 *        深拷贝 (Deep Copy) vs 浅拷贝 (Shallow Copy)
 * ============================================================
 *
 * 核心概念：
 * ---------------------------------------------------------
 *  浅拷贝 (Shallow Copy):
 *      只是简单地复制指针的值（地址），两个对象共享同一块堆内存。
 *      编译器默认提供的拷贝构造函数就是浅拷贝。
 *
 *  深拷贝 (Deep Copy):
 *      重新分配一块新的堆内存，并将原始数据复制到新内存中。
 *      两个对象各自拥有独立的堆内存，互不干扰。
 * ---------------------------------------------------------
 *
 *  图示：
 *
 *  浅拷贝（危险！）：
 *      对象A  ──ptr──┐
 *                     ├──▶  [堆内存: 数据]   ← 两个对象指向同一块内存！
 *      对象B  ──ptr──┘
 *      → 当一个对象析构释放内存后，另一个对象的指针就变成了"悬挂指针"
 *      → 再次释放 = 重复释放 (double free) → 程序崩溃！
 *
 *  深拷贝（安全）：
 *      对象A  ──ptr──▶  [堆内存: 数据（副本1）]
 *      对象B  ──ptr──▶  [堆内存: 数据（副本2）]
 *      → 各自管理自己的内存，互不干扰
 */

#include <iostream>
#include <cstring>  // for strlen, strcpy
using namespace std;

// ============================================================
//  第一部分：浅拷贝的问题演示
// ============================================================

class ShallowPerson {
public:
    int m_Age;
    char* m_Name;  // 指向堆区的指针

    // 构造函数：在堆区分配内存
    ShallowPerson(const char* name, int age) {
        m_Age = age;
        // 在堆区申请内存存放名字
        m_Name = new char[strlen(name) + 1];
        strcpy(m_Name, name);
        cout << "[ShallowPerson 构造] 创建对象, 姓名: " << m_Name
             << ", 年龄: " << m_Age
             << ", 内存地址: " << (void*)m_Name << endl;
    }

    // ⚠️ 没有自定义拷贝构造函数！
    // 编译器默认提供的拷贝构造函数执行的是 **浅拷贝**
    // 等价于：
    // ShallowPerson(const ShallowPerson& other) {
    //     m_Age = other.m_Age;
    //     m_Name = other.m_Name;  // ← 只复制了指针，没有复制数据！
    // }

    // 析构函数：释放堆区内存
    ~ShallowPerson() {
        cout << "[ShallowPerson 析构] 释放对象, 姓名: " << m_Name
             << ", 内存地址: " << (void*)m_Name << endl;
        if (m_Name != nullptr) {
            delete[] m_Name;
            m_Name = nullptr;
        }
    }
};

// ============================================================
//  第二部分：深拷贝的正确实现
// ============================================================

class DeepPerson {
public:
    int m_Age;
    char* m_Name;

    // 构造函数
    DeepPerson(const char* name, int age) {
        m_Age = age;
        m_Name = new char[strlen(name) + 1];
        strcpy(m_Name, name);
        cout << "[DeepPerson 构造] 创建对象, 姓名: " << m_Name
             << ", 年龄: " << m_Age
             << ", 内存地址: " << (void*)m_Name << endl;
    }

    // ✅ 自定义拷贝构造函数 —— 深拷贝！
    DeepPerson(const DeepPerson& other) {
        m_Age = other.m_Age;

        // 🔑 关键区别：重新在堆区申请一块新的内存
        m_Name = new char[strlen(other.m_Name) + 1];
        strcpy(m_Name, other.m_Name);  // 把数据复制到新内存

        cout << "[DeepPerson 拷贝构造] 深拷贝对象, 姓名: " << m_Name
             << ", 新内存地址: " << (void*)m_Name
             << " (原地址: " << (void*)other.m_Name << ")" << endl;
    }

    // ✅ 赋值运算符重载 —— 也需要深拷贝！
    DeepPerson& operator=(const DeepPerson& other) {
        if (this == &other) return *this;  // 防止自我赋值

        // 先释放旧内存
        delete[] m_Name;

        // 再申请新内存并复制
        m_Age = other.m_Age;
        m_Name = new char[strlen(other.m_Name) + 1];
        strcpy(m_Name, other.m_Name);

        cout << "[DeepPerson operator=] 深拷贝赋值, 姓名: " << m_Name
             << ", 新内存地址: " << (void*)m_Name << endl;
        return *this;
    }

    // 析构函数
    ~DeepPerson() {
        cout << "[DeepPerson 析构] 释放对象, 姓名: " << m_Name
             << ", 内存地址: " << (void*)m_Name << endl;
        if (m_Name != nullptr) {
            delete[] m_Name;
            m_Name = nullptr;
        }
    }
};

// ============================================================
//  演示函数
// ============================================================

// 演示浅拷贝的问题（注意：实际运行可能会崩溃！）
void demo_shallow_copy_problem() {
    cout << "\n========================================" << endl;
    cout << "  演示 1：浅拷贝的问题（仅说明，不实际运行危险代码）" << endl;
    cout << "========================================\n" << endl;

    cout << "假设我们创建了：" << endl;
    cout << "  ShallowPerson p1(\"张三\", 25);" << endl;
    cout << "  ShallowPerson p2(p1);  // 浅拷贝" << endl;
    cout << endl;
    cout << "此时 p1.m_Name 和 p2.m_Name 指向 **同一块** 堆内存！" << endl;
    cout << endl;
    cout << "当函数结束时：" << endl;
    cout << "  1. p2 先析构 → delete[] m_Name → 内存被释放 ✓" << endl;
    cout << "  2. p1 再析构 → delete[] m_Name → 重复释放同一块内存 ✗ 崩溃！" << endl;
    cout << endl;
    cout << "⚠️  这就是经典的 \"double free\" 错误！" << endl;
    cout << "⚠️  浅拷贝在涉及堆内存时是非常危险的。" << endl;
}

// 演示深拷贝的安全性
void demo_deep_copy_safe() {
    cout << "\n========================================" << endl;
    cout << "  演示 2：深拷贝的安全实现" << endl;
    cout << "========================================\n" << endl;

    DeepPerson p1("李四", 30);
    DeepPerson p2(p1);  // 调用深拷贝构造函数

    cout << "\n--- 验证两个对象是独立的 ---" << endl;
    cout << "p1: 姓名=" << p1.m_Name << ", 年龄=" << p1.m_Age
         << ", 地址=" << (void*)p1.m_Name << endl;
    cout << "p2: 姓名=" << p2.m_Name << ", 年龄=" << p2.m_Age
         << ", 地址=" << (void*)p2.m_Name << endl;

    // 证明修改一个不会影响另一个
    strcpy(p2.m_Name, "王五");
    p2.m_Age = 35;

    cout << "\n--- 修改 p2 后，p1 不受影响 ---" << endl;
    cout << "p1: 姓名=" << p1.m_Name << ", 年龄=" << p1.m_Age << endl;
    cout << "p2: 姓名=" << p2.m_Name << ", 年龄=" << p2.m_Age << endl;

    cout << "\n--- 函数结束，两个对象安全析构 ---" << endl;
    // p2 先析构，p1 后析构，各自释放自己的内存，没有问题！
}

// 演示赋值运算符的深拷贝
void demo_assignment_deep_copy() {
    cout << "\n========================================" << endl;
    cout << "  演示 3：赋值运算符的深拷贝" << endl;
    cout << "========================================\n" << endl;

    DeepPerson p1("赵六", 28);
    DeepPerson p2("临时", 0);

    cout << "\n--- 执行赋值操作 p2 = p1 ---" << endl;
    p2 = p1;  // 调用 operator=

    cout << "\np1: 姓名=" << p1.m_Name << ", 年龄=" << p1.m_Age
         << ", 地址=" << (void*)p1.m_Name << endl;
    cout << "p2: 姓名=" << p2.m_Name << ", 年龄=" << p2.m_Age
         << ", 地址=" << (void*)p2.m_Name << endl;

    cout << "\n地址不同 → 说明是深拷贝，数据独立！" << endl;
    cout << "\n--- 安全析构 ---" << endl;
}

// ============================================================
//  对比总结
// ============================================================

void print_summary() {
    cout << "\n╔══════════════════════════════════════════════════════════════╗" << endl;
    cout << "║            深拷贝 vs 浅拷贝 — 总结对比表                    ║" << endl;
    cout << "╠══════════════════════════════════════════════════════════════╣" << endl;
    cout << "║  特性          │  浅拷贝              │  深拷贝              ║" << endl;
    cout << "╠════════════════╪══════════════════════╪══════════════════════╣" << endl;
    cout << "║  内存分配      │  不分配新内存        │  分配新的堆内存      ║" << endl;
    cout << "║  数据共享      │  共享同一块内存      │  各自独立的内存      ║" << endl;
    cout << "║  修改影响      │  修改一个影响另一个  │  互不影响            ║" << endl;
    cout << "║  析构安全      │  可能 double free    │  安全                ║" << endl;
    cout << "║  性能          │  快（只复制指针）    │  慢（需要复制数据）  ║" << endl;
    cout << "║  默认行为      │  编译器默认提供      │  需要手动实现        ║" << endl;
    cout << "║  使用场景      │  无指针成员时可用    │  有指针成员时必须用  ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
    cout << "💡 黄金法则（Rule of Three / Rule of Five）：" << endl;
    cout << "   如果你的类需要自定义以下任意一个，那通常三个都需要自定义：" << endl;
    cout << "   1. 析构函数 (Destructor)" << endl;
    cout << "   2. 拷贝构造函数 (Copy Constructor)" << endl;
    cout << "   3. 拷贝赋值运算符 (Copy Assignment Operator)" << endl;
    cout << endl;
    cout << "   C++11 扩展为 Rule of Five，额外需要：" << endl;
    cout << "   4. 移动构造函数 (Move Constructor)" << endl;
    cout << "   5. 移动赋值运算符 (Move Assignment Operator)" << endl;
}

// ============================================================
//  主函数
// ============================================================

int main() {
    cout << "╔══════════════════════════════════════════════════════════════╗" << endl;
    cout << "║         C++ 深拷贝 (Deep Copy) vs 浅拷贝 (Shallow Copy)    ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════════╝" << endl;

    // 演示 1：浅拷贝的问题（安全说明，不会崩溃）
    demo_shallow_copy_problem();

    // 演示 2：深拷贝的安全实现
    demo_deep_copy_safe();

    // 演示 3：赋值运算符的深拷贝
    demo_assignment_deep_copy();

    // 打印总结对比表
    print_summary();

    cout << "\n程序正常结束，没有内存错误！" << endl;
    return 0;
}
