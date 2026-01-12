#include <iostream>
using namespace std;
#include <string>
#include <array>

struct Student
{
    string name;
    int age;
};

struct Teacher
{
    string name;
    Student studentArray[5];
};

void operate(Teacher *teachers, int len1)
{
    char nameSeed1 = 'A';
    for (int i = 0; i < len1; i++)
    {
        teachers[i].name = "Teacher_";
        teachers[i].name += nameSeed1++;

        int j = 0;
        char nameSeed2 = 'A';
        for (auto &stu_arr : teachers[i].studentArray)
        {
            stu_arr.name = "Student_";
            stu_arr.name += nameSeed1;
            stu_arr.name += "_";
            stu_arr.name += nameSeed2++;
            stu_arr.age = 18 + j++;
        }
    }
}

void print_all(Teacher *t, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << t[i].name << "\n\n";
        for (auto &stu : t[i].studentArray)
        {
            cout << stu.name << "'s age is " << stu.age << endl;
        }
        cout << "\n";
    }
}

int main()
{
    Teacher teachers[3];
    int len = sizeof(teachers) / sizeof(teachers[0]);
    operate(teachers, len);
    print_all(teachers, len);

    return 0;
}