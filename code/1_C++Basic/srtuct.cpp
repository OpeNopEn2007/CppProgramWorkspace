#include <iostream>
using namespace std;
#include <string>

struct stu
{
    string name;
    int score;
};

struct teacher
{
    string name;
    stu studentArray[5];
};

void fun(teacher *pt, int len1, int len2)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < len1; i++)
    {
        pt[i].name = "Teacher_";
        pt[i].name += nameSeed[i];
        cout << pt[i].name << endl;
        stu *ps = pt[i].studentArray;

        for (int j = 0; j < len2; j++)
        {

            ps[j].name = "Student_";
            ps[j].name += nameSeed[j];
            cout << ps[j].name << "\t";
        }
        cout << endl
             << endl;
    }
}

int main()
{
    teacher TeacherArray[3];
    const int len1 = sizeof(TeacherArray) / sizeof(TeacherArray[0]);
    const int len2 = sizeof(TeacherArray[0].studentArray) / sizeof(TeacherArray[0].studentArray[0]);
    fun(TeacherArray, len1, len2);
}