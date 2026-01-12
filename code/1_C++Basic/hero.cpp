#include <iostream>
using namespace std;
#include <string>

/*
1.设计英雄结构体

2.创建数组存放5名英雄

3.对数组进行排序，按照年龄升序排序

4.对排序后的结果进行打印输出

*/

struct hero
{
    string name;
    int age;
    string sex;
};

void bubbleSort(hero hero_arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (hero_arr[j].age > hero_arr[j + 1].age)
            {
                hero temp = hero_arr[j];
                hero_arr[j] = hero_arr[j + 1];
                hero_arr[j + 1] = temp;
            }
        }
    }
}

void printHero(hero hero_arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        hero &h = hero_arr[i];
        cout << h.name << ", " << h.age << ", " << h.sex << endl;
    }
}

int main()
{
    hero hero_arr[5] = {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"}};

    int len = sizeof(hero_arr) / sizeof(hero_arr[0]);
    bubbleSort(hero_arr, len);
    printHero(hero_arr, len);

    return 0;
}
