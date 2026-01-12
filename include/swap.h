#include <iostream>
using namespace std;

void swap(int n1, int n2)
{
    int temp = n1;
    n2 = n1;
    n1 = n2;
    cout << (long long)&n1 << endl
         << (long long)&n2 << endl;
}