// 案例描述：系统随机生成一个1到100之间的数字，玩家进行猜测，如果猜错，提示玩家数字过大或过小，如果猜对恭喜玩家胜利，并且退出游戏。

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    int res = rand() % 100 + 1;
    int gus;

    do
    {
        cout << "Input the number you guess:";
        cin >> gus;
        cout << (gus > res ? "Too Big!" : "Too Small!")<<endl;
    } while (gus != res);
    cout << "Bingo!"<<endl;

    system("pause");
    return 0;
}