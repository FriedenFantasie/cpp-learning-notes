#include <iostream>

using namespace std;

int main()
{
    int* nullPointer = nullptr;

    cout << "空指针演示：" << endl;
    cout << "nullPointer 保存的地址：" << nullPointer << endl;

    if (nullPointer == nullptr) {
        cout << "nullPointer 是空指针，不能解引用。" << endl;
    }

    cout << endl;
    cout << "野指针演示：" << endl;

    int* wildPointer;

    cout << "wildPointer 是未初始化的指针。" << endl;
    cout << "它可能指向任意未知地址，不能直接使用。" << endl;
    cout << "错误示例：不要写 *wildPointer = 100;" << endl;

    wildPointer = nullptr;

    cout << "把 wildPointer 设置为 nullptr 后，它就不再是野指针。" << endl;

    return 0;
}
