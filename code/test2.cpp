#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        int cnt = 0;
        for (auto &&i : str)
        {
            if (ispunct(i))
            {
                cnt++;
            }
        }
    cout << cnt << endl;
    }

    system("pause");
    return 0;
}