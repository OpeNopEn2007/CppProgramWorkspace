#include <iostream>
using namespace std;

int main()
{

    /*
    // 练习案例： 三只小猪称体重
    // 有三只小猪ABC，请分别输入三只小猪的体重，并且判断哪只小猪最重？
    int a1, a2, a3 = 0;
    cout << "请分别输入三只小猪的体重：";
    cin >> a1 >> a2 >> a3;
    if (a1 > a2)
    {
        if (a1 > a3)
        {
            cout << a1;
        }
        else
        {
            cout << a3;
        }
    }
    else
    {
        if (a2 > a3)
        {
            cout << a2;
        }
        else
        {
            cout << a3;
        }
    }*/


    //三目运算

    int a = 10;
    int b = 20;
    int c = 0;

    c = a > b ? a : b;
    cout << "c = " << c << endl;

    // C++中三目运算符返回的是变量,可以继续赋值

    (a > b ? a : b) = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;


    
    system("pause");
    return 0;
}