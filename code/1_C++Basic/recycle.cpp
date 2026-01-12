#include <iostream>
#include <cmath>
using namespace std;

/*
水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身

例如：1^3 + 5^3+ 3^3 = 153

请利用do...while语句，求出所有3位数中的水仙花数
*/

int main()
{
    int n = 100, a, b, c;
    do
    {
        c = n % 10;
        b = n / 10 % 10;
        a = n / 100;
        if (pow(a, 3) + pow(b, 3) + pow(c, 3) == n)
        {
            cout << n++ << endl;
        }
    } while (n < 1000);

    for (int i = 100; i < 1000; i++)
    {
        c = n % 10;
        b = n / 10 % 10;
        a = n / 100;
        if (pow(a, 3) + pow(b, 3) + pow(c, 3) == n)
        {
            cout << n++ << endl;
        }

        system("puase");
        return 0;
    }
}
