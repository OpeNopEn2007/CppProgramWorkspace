#include <iostream>
#include <string>
using namespace std;

struct student
{
    string name;
    int age;
};

void fun(student *p, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << p[i].name << " " << p[i].age << endl;
    }
}

int main()
{

    student stuArray[3] = {
        {"111", 1},
        {"222", 2},
        {"333", 3}};
    fun(stuArray, 3);

    return 0;
}
