#include <iostream> // 引入输入输出头文件，用来使用 cout、cin、endl
#include <string> // 引入字符串头文件，用来使用 string 类型

using namespace std; // 使用标准命名空间

const int MAX_CONTACTS = 1000; // 通讯录最多保存 1000 个联系人
const int INPUT_OK = 1; // 表示输入成功，进入下一步
const int INPUT_BACK = 0; // 表示返回上一步
const int INPUT_CANCEL = -1; // 表示取消当前功能，返回主菜单

struct Contact { // 定义联系人结构体
    string name; // 姓名
    int sex; // 性别，1 表示男，2 表示女
    int age; // 年龄
    string phone; // 联系电话
    string address; // 家庭住址
}; // Contact 结构体结束

struct AddressBook { // 定义通讯录结构体
    Contact contacts[MAX_CONTACTS]; // 联系人数组
    int size; // 当前联系人数量
}; // AddressBook 结构体结束

void showMenu() // 显示主菜单
{
    cout << "==============================" << endl;
    cout << "      通讯录管理系统" << endl;
    cout << "==============================" << endl;
    cout << "1. 添加联系人" << endl;
    cout << "2. 显示联系人" << endl;
    cout << "3. 删除联系人" << endl;
    cout << "4. 查找联系人" << endl;
    cout << "5. 修改联系人" << endl;
    cout << "6. 清空联系人" << endl;
    cout << "0. 退出通讯录" << endl;
    cout << "==============================" << endl;
    cout << "请选择功能：";
}

void showContact(const Contact& contact) // 显示一个联系人的信息
{
    cout << "姓名：" << contact.name << "\t";
    cout << "性别：" << (contact.sex == 1 ? "男" : "女") << "\t";
    cout << "年龄：" << contact.age << "\t";
    cout << "电话：" << contact.phone << "\t";
    cout << "地址：" << contact.address << endl;
}

bool parsePositiveInt(const string& text, int& value) // 把字符串转换成正整数
{
    if (text.empty()) { // 如果字符串为空，转换失败
        return false;
    }

    value = 0; // 先把结果清零

    for (int i = 0; i < static_cast<int>(text.size()); i++) { // 逐个检查字符
        if (text[i] < '0' || text[i] > '9') { // 只允许数字字符
            return false;
        }

        value = value * 10 + (text[i] - '0'); // 把当前数字合并到结果中
    }

    return true; // 转换成功
}

int inputStringStep(const string& prompt, string& value, bool canBack) // 输入字符串，支持 b 返回上一步、0 取消
{
    while (true) { // 循环直到用户输入有效内容
        cout << prompt; // 输出提示
        cin >> value; // 接收输入

        if (value == "0") { // 输入 0 表示取消当前功能
            cout << "已取消当前操作，返回主菜单。" << endl;
            return INPUT_CANCEL;
        }

        if (value == "b" || value == "B") { // 输入 b 表示返回上一步
            if (canBack) { // 如果当前步骤允许返回
                return INPUT_BACK;
            }

            cout << "当前已经是第一步，不能再返回上一步。" << endl;
            continue;
        }

        return INPUT_OK; // 普通字符串输入成功
    }
}

int inputIntStep(const string& prompt, int& value, bool canBack) // 输入整数，支持 b 返回上一步、0 取消
{
    string text; // 先用字符串接收，方便判断 b 和 0

    while (true) { // 循环直到用户输入有效整数
        cout << prompt; // 输出提示
        cin >> text; // 接收输入

        if (text == "0") { // 输入 0 表示取消当前功能
            cout << "已取消当前操作，返回主菜单。" << endl;
            return INPUT_CANCEL;
        }

        if (text == "b" || text == "B") { // 输入 b 表示返回上一步
            if (canBack) { // 如果当前步骤允许返回
                return INPUT_BACK;
            }

            cout << "当前已经是第一步，不能再返回上一步。" << endl;
            continue;
        }

        if (!parsePositiveInt(text, value)) { // 判断输入是否是正整数
            cout << "输入格式错误，请输入数字。" << endl;
            continue;
        }

        return INPUT_OK; // 整数输入成功
    }
}

int inputContactField(Contact& contact, int fieldIndex, bool canBack) // 输入或修改联系人某一个字段
{
    int result = INPUT_OK; // 保存输入函数返回结果

    switch (fieldIndex) { // 根据字段编号决定输入哪一项
    case 0:
        result = inputStringStep("请输入姓名（b-上一步，0-取消）：", contact.name, canBack);
        break;
    case 1:
        while (true) {
            result = inputIntStep("请输入性别（1-男，2-女，b-上一步，0-取消）：", contact.sex, canBack);

            if (result != INPUT_OK) {
                return result;
            }

            if (contact.sex == 1 || contact.sex == 2) {
                break;
            }

            cout << "性别输入错误，只能输入 1 或 2。" << endl;
        }
        break;
    case 2:
        result = inputIntStep("请输入年龄（b-上一步，0-取消）：", contact.age, canBack);
        break;
    case 3:
        result = inputStringStep("请输入联系电话（b-上一步，0-取消）：", contact.phone, canBack);
        break;
    case 4:
        result = inputStringStep("请输入家庭住址（b-上一步，0-取消）：", contact.address, canBack);
        break;
    default:
        return INPUT_CANCEL;
    }

    return result; // 返回当前字段输入结果
}

int confirmContact(Contact& contact, const string& actionName) // 保存前确认，并支持修改打错的字段
{
    string choice; // 保存用户选择

    while (true) { // 反复确认，直到保存或取消
        cout << endl;
        cout << "请确认联系人信息：" << endl;
        showContact(contact);
        cout << "输入 y " << actionName << "，输入 1-5 修改对应字段，输入 b 返回上一步，输入 0 取消：" << endl;
        cout << "1. 姓名  2. 性别  3. 年龄  4. 电话  5. 地址" << endl;
        cout << "请选择：";
        cin >> choice;

        if (choice == "y" || choice == "Y") { // 确认保存
            return INPUT_OK;
        }

        if (choice == "0") { // 取消保存
            cout << "已取消当前操作，返回主菜单。" << endl;
            return INPUT_CANCEL;
        }

        if (choice == "b" || choice == "B") { // 返回上一步，也就是回到地址输入
            return INPUT_BACK;
        }

        int fieldIndex = 0; // 保存要修改的字段编号

        if (!parsePositiveInt(choice, fieldIndex) || fieldIndex < 1 || fieldIndex > 5) {
            cout << "输入有误，请重新选择。" << endl;
            continue;
        }

        int result = inputContactField(contact, fieldIndex - 1, true); // 修改指定字段

        if (result == INPUT_CANCEL) { // 修改字段时选择取消
            return INPUT_CANCEL;
        }
    }
}

bool fillContactSteps(Contact& contact, int startStep) // 从指定步骤开始填写联系人字段
{
    int step = startStep; // 当前填写到第几个字段，0 姓名，1 性别，2 年龄，3 电话，4 地址

    while (step < 5) { // 5 个字段都输入完之前一直循环
        int result = inputContactField(contact, step, step > 0); // 输入当前字段，第一步不能返回上一步

        if (result == INPUT_CANCEL) { // 用户输入 0，取消当前功能
            return false;
        }

        if (result == INPUT_BACK) { // 用户输入 b，返回上一步
            step--;
            continue;
        }

        step++; // 当前字段输入成功，进入下一字段
    }

    return true; // 所有字段填写完成
}

bool fillContact(Contact& contact, const string& actionName) // 按步骤填写联系人，支持返回上一步
{
    if (!fillContactSteps(contact, 0)) { // 从姓名开始填写联系人信息
        return false;
    }

    while (true) { // 保存前确认；如果用户选 b，就回到最后一个字段
        int confirmResult = confirmContact(contact, actionName);

        if (confirmResult == INPUT_OK) {
            return true;
        }

        if (confirmResult == INPUT_BACK) {
            if (!fillContactSteps(contact, 4)) { // 从家庭住址这一步重新填写，仍可继续按 b 往前退
                return false;
            }
            continue;
        }

        return false;
    }
}

int findContactIndex(const AddressBook& book, const string& name) // 按姓名查找联系人下标
{
    for (int i = 0; i < book.size; i++) {
        if (book.contacts[i].name == name) {
            return i;
        }
    }

    return -1;
}

void addContact(AddressBook& book) // 添加联系人
{
    if (book.size >= MAX_CONTACTS) {
        cout << "通讯录已满，无法继续添加。" << endl;
        return;
    }

    Contact contact; // 定义临时联系人

    if (!fillContact(contact, "保存")) { // 填写并确认联系人信息
        return;
    }

    book.contacts[book.size] = contact; // 保存到数组末尾
    book.size++; // 联系人数量加 1

    cout << "添加成功。" << endl;
}

void showAllContacts(const AddressBook& book) // 显示所有联系人
{
    if (book.size == 0) {
        cout << "当前通讯录为空。" << endl;
        return;
    }

    cout << "当前共有 " << book.size << " 个联系人：" << endl;

    for (int i = 0; i < book.size; i++) {
        cout << i + 1 << ". ";
        showContact(book.contacts[i]);
    }
}

void deleteContact(AddressBook& book) // 删除联系人
{
    string name;

    if (inputStringStep("请输入要删除的联系人姓名（0-取消）：", name, false) == INPUT_CANCEL) {
        return;
    }

    int index = findContactIndex(book, name);

    if (index == -1) {
        cout << "查无此人。" << endl;
        return;
    }

    showContact(book.contacts[index]);
    cout << "确定删除该联系人吗？（y-确认，其他-取消）：";
    string confirm;
    cin >> confirm;

    if (confirm != "y" && confirm != "Y") {
        cout << "已取消删除。" << endl;
        return;
    }

    for (int i = index; i < book.size - 1; i++) {
        book.contacts[i] = book.contacts[i + 1];
    }

    book.size--;
    cout << "删除成功。" << endl;
}

void findContact(const AddressBook& book) // 查找联系人
{
    string name;

    if (inputStringStep("请输入要查找的联系人姓名（0-取消）：", name, false) == INPUT_CANCEL) {
        return;
    }

    int index = findContactIndex(book, name);

    if (index == -1) {
        cout << "查无此人。" << endl;
        return;
    }

    cout << "查找结果：" << endl;
    showContact(book.contacts[index]);
}

void modifyContact(AddressBook& book) // 修改联系人
{
    string name;

    if (inputStringStep("请输入要修改的联系人姓名（0-取消）：", name, false) == INPUT_CANCEL) {
        return;
    }

    int index = findContactIndex(book, name);

    if (index == -1) {
        cout << "查无此人。" << endl;
        return;
    }

    Contact editedContact = book.contacts[index]; // 先复制一份，确认后再覆盖原数据

    cout << "当前联系人信息：" << endl;
    showContact(editedContact);

    if (!fillContact(editedContact, "修改")) { // 重新填写并确认修改后的信息
        return;
    }

    book.contacts[index] = editedContact; // 用户确认后，再保存修改
    cout << "修改成功。" << endl;
}

void clearContacts(AddressBook& book) // 清空联系人
{
    string confirm;

    cout << "确定要清空所有联系人吗？（y-确认，其他-取消）：";
    cin >> confirm;

    if (confirm != "y" && confirm != "Y") {
        cout << "已取消清空。" << endl;
        return;
    }

    book.size = 0;
    cout << "通讯录已清空。" << endl;
}

int main() // 主函数
{
    AddressBook book;
    book.size = 0;

    int choice = 0;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addContact(book);
            break;
        case 2:
            showAllContacts(book);
            break;
        case 3:
            deleteContact(book);
            break;
        case 4:
            findContact(book);
            break;
        case 5:
            modifyContact(book);
            break;
        case 6:
            clearContacts(book);
            break;
        case 0:
            cout << "欢迎下次使用通讯录管理系统。" << endl;
            return 0;
        default:
            cout << "输入有误，请重新选择。" << endl;
            break;
        }

        cout << endl;
    }
}
