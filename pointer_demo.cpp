#include <iostream>
#include <string>
using namespace std;

/**
 * C++指针详解示例程序
 * 
 * 本程序详细演示了C++中指针的定义、使用方法和常见应用场景
 */

// 函数声明
void basicPointerDemo();
void pointerArithmeticDemo();
void arrayAndPointersDemo();
void pointerToPointerDemo();
void functionPointersDemo();
void constPointerDemo();
void pointerToStructDemo();
void dynamicMemoryDemo();
void referenceVsPointerDemo();
int* createArray(int size);
void modifyValue(int* ptr);
void printArray(const int* arr, int size);
int add(int a, int b);
int subtract(int a, int b);
int calculate(int a, int b, int (*operation)(int, int)); // 添加缺少的函数声明

int main() {
    cout << "=== C++指针详解 ===" << endl << endl;
    
    int choice;
    do {
        cout << "\n请选择要演示的内容：" << endl;
        cout << "1. 基本指针定义与使用" << endl;
        cout << "2. 指针算术操作" << endl;
        cout << "3. 指针与数组" << endl;
        cout << "4. 指针的指针" << endl;
        cout << "5. 函数指针" << endl;
        cout << "6. const指针与指向const的指针" << endl;
        cout << "7. 指向结构体的指针" << endl;
        cout << "8. 动态内存分配" << endl;
        cout << "9. 指针与引用的比较" << endl;
        cout << "0. 退出程序" << endl;
        cout << "请输入选择 (0-9): ";
        cin >> choice;
        
        switch(choice) {
            case 1: basicPointerDemo(); break;
            case 2: pointerArithmeticDemo(); break;
            case 3: arrayAndPointersDemo(); break;
            case 4: pointerToPointerDemo(); break;
            case 5: functionPointersDemo(); break;
            case 6: constPointerDemo(); break;
            case 7: pointerToStructDemo(); break;
            case 8: dynamicMemoryDemo(); break;
            case 9: referenceVsPointerDemo(); break;
            case 0: cout << "感谢使用指针演示程序！" << endl; break;
            default: cout << "无效选择，请重新输入。" << endl;
        }
        
    } while(choice != 0);
    
    return 0;
}

/**
 * 1. 基本指针定义与使用
 * 演示指针的基本声明、赋值和解引用操作
 */
void basicPointerDemo() {
    cout << "\n=== 基本指针定义与使用 ===" << endl;
    
    // 1. 指针的声明
    int* ptr1;     // 方式1：类型* 标识符
    int *ptr2;     // 方式2：类型 *标识符
    int *ptr3, var; // 注意：这里ptr3是指针，但var是普通变量
    
    // 2. 获取变量的地址并存储在指针中
    int number = 42;
    ptr1 = &number; // &操作符获取变量的内存地址
    
    cout << "变量 number 的值: " << number << endl;
    cout << "变量 number 的地址: " << &number << endl;
    cout << "指针 ptr1 存储的地址: " << ptr1 << endl;
    
    // 3. 通过指针访问值（解引用）
    cout << "通过指针访问变量值: " << *ptr1 << endl; // *操作符解引用，访问指针指向的值
    
    // 4. 通过指针修改值
    *ptr1 = 100; // 修改指针指向的值
    cout << "修改后，number 的值变为: " << number << endl;
    
    // 5. 空指针
    int* nullPtr = nullptr; // 现代C++使用nullptr表示空指针
    cout << "空指针的值: " << nullPtr << endl;
    
    // 6. 指针的大小
    cout << "在此系统上，指针的大小为 " << sizeof(ptr1) << " 字节" << endl;
    
    // 7. 示例：使用指针交换两个数
    int a = 5, b = 10;
    cout << "交换前: a = " << a << ", b = " << b << endl;
    
    // 使用指针交换
    int* ptrA = &a;
    int* ptrB = &b;
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
    
    cout << "交换后: a = " << a << ", b = " << b << endl;
    
    // 8. 函数参数中的指针示例
    int value = 50;
    cout << "调用函数前，value = " << value << endl;
    modifyValue(&value); // 传递变量的地址
    cout << "调用函数后，value = " << value << endl;
}

/**
 * 通过指针修改值的函数
 */
void modifyValue(int* ptr) {
    *ptr = *ptr * 2; // 将指针指向的值乘以2
    cout << "在函数内，*ptr = " << *ptr << endl;
}

/**
 * 2. 指针算术操作
 * 演示指针与整数的加减运算
 */
void pointerArithmeticDemo() {
    cout << "\n=== 指针算术操作 ===" << endl;
    
    int numbers[5] = {10, 20, 30, 40, 50};
    int* ptr = numbers; // 指向数组第一个元素
    
    cout << "数组地址: " << numbers << endl;
    cout << "指针初始值: " << ptr << endl;
    
    // 1. 指针加法
    cout << "\n指针加法：" << endl;
    cout << "ptr    指向的值: " << *ptr << endl; // 10
    cout << "ptr + 1指向的值: " << *(ptr + 1) << endl; // 20
    cout << "ptr + 2指向的值: " << *(ptr + 2) << endl; // 30
    
    // 2. 指针减法
    ptr = &numbers[3]; // 指向第四个元素
    cout << "\n指针从第四个元素开始的减法：" << endl;
    cout << "ptr    指向的值: " << *ptr << endl; // 40
    cout << "ptr - 1指向的值: " << *(ptr - 1) << endl; // 30
    cout << "ptr - 2指向的值: " << *(ptr - 2) << endl; // 20
    
    // 3. 指针自增/自减
    ptr = numbers; // 重置为指向第一个元素
    cout << "\n指针自增操作：" << endl;
    cout << "当前 *ptr = " << *ptr << endl;
    ptr++; // 指向下一个元素
    cout << "ptr++后，*ptr = " << *ptr << endl;
    ptr++; // 再指向下一个元素
    cout << "ptr++后，*ptr = " << *ptr << endl;
    ptr--; // 回到前一个元素
    cout << "ptr--后，*ptr = " << *ptr << endl;
    
    // 4. 指针比较
    int *ptr1 = &numbers[1];
    int *ptr2 = &numbers[3];
    cout << "\n指针比较：" << endl;
    cout << "ptr1 < ptr2: " << (ptr1 < ptr2) << endl;
    cout << "ptr1 > ptr2: " << (ptr1 > ptr2) << endl;
    cout << "ptr1 == &numbers[1]: " << (ptr1 == &numbers[1]) << endl;
    
    // 5. 两个指针相减
    cout << "\n两个指针相减：" << endl;
    cout << "ptr2 - ptr1 = " << (ptr2 - ptr1) << " (元素数量)" << endl;
}

/**
 * 3. 指针与数组
 * 演示指针和数组之间的关系
 */
void arrayAndPointersDemo() {
    cout << "\n=== 指针与数组 ===" << endl;
    
    int arr[5] = {10, 20, 30, 40, 50};
    
    // 1. 数组名是指向首元素的指针
    cout << "数组名 arr 是指针: " << arr << endl;
    cout << "数组首元素地址 &arr[0]: " << &arr[0] << endl;
    cout << "它们相等吗? " << (arr == &arr[0] ? "是" : "否") << endl;
    
    // 2. 使用指针访问数组元素
    int* ptr = arr;
    cout << "\n使用指针访问数组元素：" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << arr[i] 
             << ", *(ptr + " << i << ") = " << *(ptr + i)
             << ", ptr[" << i << "] = " << ptr[i] << endl;
    }
    
    // 3. 动态创建数组
    int size = 5;
    int* dynamicArray = createArray(size);
    
    cout << "\n动态创建的数组内容：" << endl;
    for (int i = 0; i < size; i++) {
        cout << "dynamicArray[" << i << "] = " << dynamicArray[i] << endl;
    }
    
    // 4. 数组名和指针的不同之处
    cout << "\n数组名和指针的区别：" << endl;
    cout << "sizeof(arr) = " << sizeof(arr) << " (整个数组的大小)" << endl;
    cout << "sizeof(ptr) = " << sizeof(ptr) << " (指针的大小)" << endl;
    
    // 不要忘记释放动态分配的内存
    delete[] dynamicArray;
}

/**
 * 创建并初始化动态数组
 */
int* createArray(int size) {
    int* newArray = new int[size]; // 动态分配内存
    
    // 初始化数组
    for (int i = 0; i < size; i++) {
        newArray[i] = (i + 1) * 10;
    }
    
    return newArray; // 返回指向数组的指针
}

/**
 * 4. 指针的指针
 * 演示多级指针的概念
 */
void pointerToPointerDemo() {
    cout << "\n=== 指针的指针 ===" << endl;
    
    int value = 42;
    int* ptr = &value;    // 指向int的指针
    int** ptrToPtr = &ptr; // 指向指针的指针
    
    cout << "value = " << value << endl;
    cout << "ptr = " << ptr << " (value的地址)" << endl;
    cout << "*ptr = " << *ptr << " (value的值)" << endl;
    cout << "ptrToPtr = " << ptrToPtr << " (ptr的地址)" << endl;
    cout << "*ptrToPtr = " << *ptrToPtr << " (ptr的值，即value的地址)" << endl;
    cout << "**ptrToPtr = " << **ptrToPtr << " (value的值)" << endl;
    
    // 通过指针的指针修改值
    **ptrToPtr = 100;
    cout << "\n通过指针的指针修改后:" << endl;
    cout << "value = " << value << endl;
    
    // 指针数组与二维数组
    cout << "\n指针数组示例：" << endl;
    const char* names[] = {"Alice", "Bob", "Charlie"};
    
    for (int i = 0; i < 3; i++) {
        cout << "names[" << i << "] = " << names[i] << endl;
    }
    
    // 二维数组和指针的关系
    cout << "\n二维数组和指针：" << endl;
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    cout << "通过指针访问matrix[1][2]: " << *(*(matrix + 1) + 2) << endl;
}

/**
 * 5. 函数指针
 * 演示如何定义和使用函数指针
 */
void functionPointersDemo() {
    cout << "\n=== 函数指针 ===" << endl;
    
    // 1. 定义函数指针类型
    int (*operationPtr)(int, int); // 声明一个指向函数的指针，该函数接受两个int参数并返回int
    
    // 2. 将函数地址赋值给函数指针
    operationPtr = add;
    cout << "使用函数指针调用add(5, 3): " << operationPtr(5, 3) << endl;
    
    // 3. 更改函数指针指向另一个函数
    operationPtr = subtract;
    cout << "使用函数指针调用subtract(5, 3): " << operationPtr(5, 3) << endl;
    
    // 4. 函数指针数组
    int (*operations[2])(int, int) = {add, subtract};
    cout << "\n使用函数指针数组：" << endl;
    cout << "operations[0](10, 5): " << operations[0](10, 5) << endl;
    cout << "operations[1](10, 5): " << operations[1](10, 5) << endl;
    
    // 5. 将函数指针作为参数
    cout << "\n将函数指针作为参数：" << endl;
    cout << "使用add函数: " << calculate(10, 5, add) << endl;
    cout << "使用subtract函数: " << calculate(10, 5, subtract) << endl;
}

// 用于函数指针示例的函数
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

// 接受函数指针作为参数的函数
int calculate(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

/**
 * 6. const指针与指向const的指针
 * 演示const与指针结合的各种情况
 */
void constPointerDemo() {
    cout << "\n=== const指针与指向const的指针 ===" << endl;
    
    int x = 10, y = 20;
    
    // 1. 指向常量的指针（不能通过指针修改所指向的值）
    const int* ptr1 = &x;
    // *ptr1 = 30; // 错误：不能通过ptr1修改x的值
    ptr1 = &y;     // 可以：指针本身可以指向其他地址
    
    cout << "指向常量的指针 ptr1: " << *ptr1 << endl;
    
    // 2. 常量指针（指针本身是常量，不能指向其他地址）
    int* const ptr2 = &x;
    *ptr2 = 30;    // 可以：可以通过ptr2修改x的值
    // ptr2 = &y;  // 错误：ptr2是常量，不能指向其他地址
    
    cout << "常量指针 ptr2: " << *ptr2 << ", x现在是: " << x << endl;
    
    // 3. 指向常量的常量指针（既不能通过它修改所指向的值，指针本身也不能改变）
    const int* const ptr3 = &y;
    // *ptr3 = 40;  // 错误：不能通过ptr3修改y的值
    // ptr3 = &x;   // 错误：ptr3是常量指针，不能指向其他地址
    
    cout << "指向常量的常量指针 ptr3: " << *ptr3 << endl;
    
    // 4. 使用const指针作为函数参数
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "\n数组内容：";
    printArray(arr, 5); // arr是指向常量的指针，函数不能修改数组内容
}

/**
 * 使用const指针作为参数的函数，保证不会修改数组内容
 */
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
    
    // arr[0] = 100; // 错误：不能修改arr指向的内容
}

/**
 * 7. 指向结构体的指针
 * 演示如何使用指向结构体的指针
 */
void pointerToStructDemo() {
    cout << "\n=== 指向结构体的指针 ===" << endl;
    
    // 定义结构体类型
    struct Person {
        string name;
        int age;
        string city;
    };
    
    // 创建结构体变量
    Person person1 = {"Alice", 25, "New York"};
    
    // 创建指向结构体的指针
    Person* ptrPerson = &person1;
    
    // 1. 通过指针访问结构体成员
    cout << "使用箭头运算符 -> 访问结构体成员：" << endl;
    cout << "姓名: " << ptrPerson->name << endl;
    cout << "年龄: " << ptrPerson->age << endl;
    cout << "城市: " << ptrPerson->city << endl;
    
    // 2. 另一种访问结构体成员的方式
    cout << "\n使用解引用和点运算符访问：" << endl;
    cout << "姓名: " << (*ptrPerson).name << endl;
    
    // 3. 通过指针修改结构体成员
    ptrPerson->age = 26;
    cout << "\n修改后的年龄: " << person1.age << endl;
    
    // 4. 结构体数组与指针
    Person people[3] = {
        {"Alice", 25, "New York"},
        {"Bob", 30, "Boston"},
        {"Charlie", 35, "Chicago"}
    };
    
    Person* peoplePtr = people;
    
    cout << "\n使用指针遍历结构体数组：" << endl;
    for (int i = 0; i < 3; i++, peoplePtr++) {
        cout << "Person " << (i + 1) << ": " 
             << peoplePtr->name << ", "
             << peoplePtr->age << ", "
             << peoplePtr->city << endl;
    }
    
    // 5. 动态分配结构体
    Person* dynamicPerson = new Person{"David", 40, "Denver"};
    
    cout << "\n动态分配的结构体：" << endl;
    cout << dynamicPerson->name << ", " 
         << dynamicPerson->age << ", " 
         << dynamicPerson->city << endl;
    
    // 不要忘记释放内存
    delete dynamicPerson;
}

/**
 * 8. 动态内存分配
 * 演示C++中使用new和delete进行动态内存管理
 */
void dynamicMemoryDemo() {
    cout << "\n=== 动态内存分配 ===" << endl;
    
    // 1. 动态分配单个整数
    int* ptrInt = new int;
    *ptrInt = 42;
    cout << "动态分配的整数值: " << *ptrInt << endl;
    delete ptrInt; // 释放内存
    
    // 2. 动态分配并初始化
    int* ptrInt2 = new int(100);
    cout << "动态分配并初始化的整数值: " << *ptrInt2 << endl;
    delete ptrInt2;
    
    // 3. 动态分配数组
    int size;
    cout << "\n请输入想要创建的数组大小: ";
    cin >> size;
    
    int* arr = new int[size]; // 分配size大小的整数数组
    
    cout << "请输入" << size << "个整数：" << endl;
    for (int i = 0; i < size; i++) {
        cout << "元素 " << i << ": ";
        cin >> arr[i];
    }
    
    cout << "\n您输入的数组内容是：";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
    
    delete[] arr; // 使用delete[]释放数组内存
    
    // 4. 动态分配对象
    string* strPtr = new string("Hello, Dynamic Memory!");
    cout << "\n动态分配的字符串: " << *strPtr << endl;
    delete strPtr;
    
    // 5. 内存泄漏示例（注释掉以避免实际泄漏）
    cout << "\n内存泄漏问题：" << endl;
    cout << "如果分配了内存但忘记释放，就会发生内存泄漏。" << endl;
    cout << "例如： int* leak = new int[1000]; // 没有对应的delete[]" << endl;
    
    // 6. 使用智能指针避免内存泄漏（C++11及以上）
    cout << "\n现代C++推荐使用智能指针，如unique_ptr, shared_ptr等" << endl;
    cout << "例如：std::unique_ptr<int> smartPtr(new int(42));" << endl;
    cout << "      std::shared_ptr<int> sharedPtr = std::make_shared<int>(42);" << endl;
}

/**
 * 9. 指针与引用的比较
 * 演示指针和引用的异同
 */
void referenceVsPointerDemo() {
    cout << "\n=== 指针与引用的比较 ===" << endl;
    
    int value = 42;
    
    // 1. 指针
    int* ptr = &value;
    cout << "指针示例:" << endl;
    cout << "value = " << value << endl;
    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;
    
    *ptr = 100;
    cout << "修改后 value = " << value << endl;
    
    // 重新指向
    int another = 200;
    ptr = &another;
    cout << "\n指针可以重新指向：" << endl;
    cout << "*ptr 现在是 " << *ptr << endl;
    
    // 2. 引用
    int& ref = value;
    cout << "\n引用示例:" << endl;
    cout << "value = " << value << endl;
    cout << "ref = " << ref << endl;
    
    ref = 150;
    cout << "修改后 value = " << value << endl;
    
    // 引用不能重新绑定
    // ref = another; // 这只会更改value的值，不会让ref引用another
    cout << "\n引用不能重新绑定到其他对象：" << endl;
    cout << "ref = " << ref << ", value = " << value << endl;
    
    // 3. 对比表
    cout << "\n指针与引用的主要区别：" << endl;
    cout << "1. 指针可以为nullptr，引用必须初始化且不能为空" << endl;
    cout << "2. 指针可以重新指向其他变量，引用一旦绑定不能改变" << endl;
    cout << "3. 指针有自己的内存地址，引用是变量的别名" << endl;
    cout << "4. 访问指针所指的值需要解引用(*ptr)，引用直接使用" << endl;
    cout << "5. 指针适用于可能为空或需要改变指向的情况" << endl;
    cout << "6. 引用适用于函数参数和返回值，使代码更简洁" << endl;
}
