#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main() {
    cout << "===== C++中定义二维数组的各种方式 =====\n" << endl;

    // 1. 使用C风格的二维数组声明和初始化
    cout << "1. C风格的二维数组定义方式：" << endl;
    
    // 1.1 声明并初始化 - 完全初始化
    int array1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    cout << "   完全初始化示例：array1[1][2] = " << array1[1][2] << endl;
    
    // 1.2 声明并初始化 - 部分初始化（其余元素默认为0）
    int array2[3][4] = {
        {1, 2},
        {5},
        {9, 10, 11}
    };
    cout << "   部分初始化示例：array2[0][3] = " << array2[0][3] << endl;
    
    // 1.3 声明并初始化 - 一维化初始化
    int array3[2][3] = {1, 2, 3, 4, 5, 6};
    cout << "   一维方式初始化：array3[1][0] = " << array3[1][0] << endl;
    
    // 1.4 先声明后初始化
    int array4[2][3];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            array4[i][j] = i * 3 + j;
        }
    }
    cout << "   声明后初始化：array4[1][2] = " << array4[1][2] << endl;
    
    // 1.5 使用类型推断（C++11）
    auto array5 = new int[2][3]{
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "   使用auto和new：array5[1][1] = " << array5[1][1] << endl;
    delete[] array5; // 记得释放内存
    
    cout << endl;

    // 2. 使用STL容器
    cout << "2. 使用STL容器vector定义二维数组：" << endl;
    
    // 2.1 使用vector创建二维动态数组
    vector<vector<int>> vec1(3, vector<int>(4, 0)); // 3行4列，全初始化为0
    vec1[1][2] = 7;
    cout << "   直接构造：vec1[1][2] = " << vec1[1][2] << endl;
    
    // 2.2 使用vector创建并初始化
    vector<vector<int>> vec2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    cout << "   初始化列表：vec2[2][3] = " << vec2[2][3] << endl;
    
    cout << endl;

    // 3. 使用std::array（C++11）
    cout << "3. 使用std::array定义二维数组（C++11）：" << endl;
    
    // 3.1 使用std::array创建二维静态数组
    array<array<int, 4>, 3> arr1 = {{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    }};
    cout << "   使用std::array：arr1[2][1] = " << arr1[2][1] << endl;
    
    cout << endl;

    // 4. 使用指针方式
    cout << "4. 使用指针方式定义二维数组：" << endl;
    
    // 4.1 指针数组
    int *ptrArray1[3];
    for (int i = 0; i < 3; ++i) {
        ptrArray1[i] = new int[4];
        for (int j = 0; j < 4; ++j) {
            ptrArray1[i][j] = i * 4 + j;
        }
    }
    cout << "   指针数组：ptrArray1[2][3] = " << ptrArray1[2][3] << endl;
      // 释放内存
    for (int i = 0; i < 3; ++i) {
        delete[] ptrArray1[i];
    }
    
    // 4.2 指向指针的指针（双重指针）
    int **ptrArray2 = new int*[3];
    for (int i = 0; i < 3; ++i) {
        ptrArray2[i] = new int[4];
        for (int j = 0; j < 4; ++j) {
            ptrArray2[i][j] = i * 4 + j + 100;
        }
    }
    cout << "   双重指针：ptrArray2[1][2] = " << ptrArray2[1][2] << endl;
    
    // 释放内存
    for (int i = 0; i < 3; ++i) {
        delete[] ptrArray2[i];
    }
    delete[] ptrArray2;
    
    // 4.3 使用单个一维数组模拟二维数组
    int *singleArray = new int[3 * 4];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            // 行主序访问
            singleArray[i * 4 + j] = i * 4 + j + 200;
        }
    }
    cout << "   一维模拟：singleArray[1*4+2] = " << singleArray[1 * 4 + 2] << endl;
    delete[] singleArray;
    
    cout << endl;

    // 5. C++17 多维数组初始化（如果编译器支持）
    cout << "5. 使用其他现代C++特性：" << endl;
    
    // 在C++17中可以使用结构化绑定
    int array6[2][2] = {{1, 2}, {3, 4}};
    cout << "   C++17结构化绑定演示：" << endl;
    cout << "   - 将二维数组的第一行解包：" << endl;
    auto [x, y] = array6[0]; // 结构化绑定第一行
    cout << "     x = " << x << ", y = " << y << endl;

    cout << "\n所有方法都已展示完毕!" << endl;
    
    return 0;
}