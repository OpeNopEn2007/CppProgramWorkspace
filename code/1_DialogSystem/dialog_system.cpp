#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#define MAX 1000

// 设置输出通讯录每列的宽度：根据内容估计最大宽度
const int nameWidth = 12;  // 姓名列宽
const int sexWidth = 8;    // 性别列宽
const int ageWidth = 8;    // 年龄列宽
const int phoneWidth = 16; // 电话号码列宽
const int addrWidth = 16;  // 地址列宽

struct Person
{
    string Name;
    int Sex;
    int Age;
    string Phone;
    string Addr;
};

struct AddrBook
{
    Person personArray[MAX];
    int Size = 0;
};

void showMenu();
void addPerson(AddrBook *AddrBook);
void printPerson(AddrBook *adb, int i);
void showPerson(AddrBook *AddrBook);
int isExist(AddrBook *adb, string f_name);
void delPerson(AddrBook *adb);
void findPerson(AddrBook *adb);
void modifyPerson(AddrBook *adb);
void cleanPerson(AddrBook *adb);

int main()
{
    AddrBook ab;
    int op_n;
    while (true)
    {
        showMenu();
        cin >> op_n;

        switch (op_n)
        {
        case 1:
            addPerson(&ab);
            break;

        case 2:
            showPerson(&ab);
            break;

        case 3:
            delPerson(&ab);
            break;

        case 4:
            findPerson(&ab);
            break;

        case 5:
            modifyPerson(&ab);
            break;

        case 6:
            cleanPerson(&ab);
            break;

        case 0:
            cout << "欢迎下次使用！" << endl;
            system("pause");
            return 0;
            break;

        default:
            cout << "输入错误！请重新操作！";
            break;
        }
        system("pause");
        system("cls");
    }
}

void showMenu()
{
    cout << " ———————————————\n"
         << "| 1、添加联系人 |\n"
         << "| 2、显示联系人 |\n"
         << "| 3、删除联系人 |\n"
         << "| 4、查找联系人 |\n"
         << "| 5、修改联系人 |\n"
         << "| 6、清空联系人 |\n"
         << "| 0、退出通讯录 |\n"
         << " ———————————————\n"
         << endl;
    return;
}

void addPerson(AddrBook *adb)
{
    if (adb->Size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        adb->personArray[adb->Size].Name = name;

        int sex;
        while (true)
        {
            cout << "请输入性别：\n1 —— 男\n2 —— 女" << endl;
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                break;
            }
            cout << "输入有误！" << endl;
        }
        adb->personArray[adb->Size].Sex = sex;

        int age;
        cout << "请输入年龄：" << endl;
        cin >> age;
        adb->personArray[adb->Size].Age = age;

        string phone;
        cout << "请输入电话号码：" << endl;
        cin >> phone;
        adb->personArray[adb->Size].Phone = phone;

        string addr;
        cout << "请输入地址：" << endl;
        cin >> addr;
        adb->personArray[adb->Size].Addr = addr;

        cout << "成功添加联系人！" << endl;
        adb->Size++;
    }
}
void printPerson(AddrBook *adb, int i)
{
    auto &p = adb->personArray;
    cout << setw(nameWidth) << p[i].Name
         << setw(sexWidth) << ((p[i].Sex == 1) ? "男" : "女")
         << setw(ageWidth) << p[i].Age
         << setw(phoneWidth) << p[i].Phone
         << setw(addrWidth) << p[i].Addr
         << endl;
}
void showPerson(AddrBook *adb)
{
    if (adb->Size > 0)
    {

        // 输出表头：使用std::setw设置固定宽度，std::left左对齐
        cout << left; // 设置整体左对齐
        cout << setw(nameWidth) << "姓名"
             << setw(sexWidth) << "性别"
             << setw(ageWidth) << "年龄"
             << setw(phoneWidth) << "电话号码"
             << setw(addrWidth) << "地址"
             << endl;

        // 输出数据行
        for (int i = 0; i < adb->Size; i++)
        {
            printPerson(adb, i);
        }
    }
    else
    {
        cout << "当前通讯录为空！" << endl;
    }
}
int isExist(AddrBook *adb, string f_name)
{
    for (int i = 0; i < adb->Size; i++)
    {
        if (adb->personArray[i].Name == f_name)
        {
            return i;
        }
    }
    return -1;
}
void delPerson(AddrBook *adb)
{
    cout << "请输入您要删除的联系人：" << endl;
    string name;
    cin >> name;

    int re = isExist(adb, name);
    if (re == -1)
    {
        cout << "查无此人！" << endl;
    }
    else
    {
        for (int i = re; i < adb->Size; i++)
        {
            adb->personArray[i] = adb->personArray[i + 1];
        }
        adb->Size--; // 更新联系人数组长度
        cout << "删除成功！" << endl;
    }
}
void findPerson(AddrBook *adb)
{
    cout << "请输入您要查找的联系人：" << endl;
    string name;
    cin >> name;
    int re = isExist(adb, name);
    if (re == -1)
    {
        cout << "查无此人！" << endl;
    }
    else
    {
        system("cls");
        showMenu();
        cout << left;
        cout << setw(nameWidth) << "姓名"
             << setw(sexWidth) << "性别"
             << setw(ageWidth) << "年龄"
             << setw(phoneWidth) << "电话号码"
             << setw(addrWidth) << "地址"
             << endl;
        printPerson(adb, re);
    }
}
void modifyPerson(AddrBook *adb)
{
    showPerson(adb);
    cout << "请输入您要修改的联系人：" << endl;
    string name;
    cin >> name;
    int re = isExist(adb, name);
    if (re == -1)
    {
        cout << "查无此人！" << endl;
    }
    else
    {
        cout << "需要修改的项请输入新的内容，无需修改的项可以输入“404”以维持原数据：";

        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        if (name != "404")
        {
            adb->personArray[re].Name = name;
        }

        int sex;
        while (true)
        {
            cout << "请输入性别：\n1 —— 男\n2 —— 女" << endl;
            cin >> sex;
            if (sex == 404)
            {
                break;
            }
            else
            {
                if (sex == 1 || sex == 2)
                {
                    adb->personArray[re].Sex = sex;
                    break;
                }
                else
                {
                    cout << "输入有误！" << endl;
                }
            }
        }

        int age;
        cout << "请输入年龄：" << endl;
        cin >> age;
        if (age != 404)
        {
            adb->personArray[re].Age = age;
        }

        string phone;
        cout << "请输入电话号码：" << endl;
        cin >> phone;
        if (phone != "404")
        {
            adb->personArray[re].Phone = phone;
        }

        string addr;
        cout << "请输入地址：" << endl;
        cin >> addr;
        if (addr != "404")
        {
            adb->personArray[re].Addr = addr;
        }

        cout << "成功修改联系人！" << endl;
    }
}
void cleanPerson(AddrBook *adb)
{
    string in;
    cout << "确定要清空联系人？确定请输入Y，返回请输入任意其他字符：" << endl;
    cin >> in;
    if (in == "Y")
    {
        adb->Size = 0; // 逻辑清空
        cout << "已成功清空联系人！" << endl;
    }
}