#include <iostream>
#include <queue>
using namespace std;
/**
， 障碍格子：将输入的障碍格子填写到board当中对应格上，设置为-1；
2， 起始格子和结束格子：将起始点start和结束点end，这两个点记录下来，在board中这两个
格子设置为0；
3， 围墙：在8*8的棋盘外面，上下左右各加2行2列做围墙，围墙和障碍一样，设置为-1；
4， 除障碍、围墙、起始、结束格子这些格子特殊对待之外，其余格子全部初始化为0；
5， 队列初始为空。队列是用来在骑士做 “日字型”对角跳的时候，候选位置放入队列中的
一个辅助的数据结构，以便于“广度优先搜索”。
6， 从起点开始，将这个位置所能跳的周围8个位置都检查一下：只要未标记，就标记为前一个
位置值加1，并将该位置入队列；
    如果不能标记（比如障碍或围墙等），就跳过，继续检查下一个位置，一共八个骑士所能
跳的位置。
7， 取出队列首个位置结点，又继续检查这个结点周围的8个位置，类同上一步，直到找到对终
点标记位置。
8， 最后，输出终点所标记的数值（正数），就是骑士所需的最少移动步数，若为0表示终点无
法标记到，输出：“not reachable”这样的信息。

1--5为初始化步骤，在标记之前就应该做好棋盘和相关辅助数据结构的初始化；
6--8为标记过程。
**/
void jump();
int board[12][12];
int xend;
int yend;

class point
{
  public:
    int x;
    int y;
    int number;
};
queue<point> q1;

void init() //初始化
{
    for (int i = 2; i < 10; i++)
        for (int j = 2; j < 10; j++)
            board[i][j] = 0;
    //围墙初始化为-1
    for (int i = 0; i < 12; i++)
    {
        board[i][0] = -1;
        board[i][1] = -1;
        board[i][10] = -1;
        board[i][11] = -1;
    }
    for (int i = 2; i < 10; i++)
    {
        board[0][i] = -1;
        board[1][i] = -1;
        board[10][i] = -1;
        board[11][i] = -1;
    }
}

int main()
{
    int b;
    int k = 1;
    init();
    cin >> b;
    //围墙
    while (b != -1)
    {
        for (int i = 0; i < b; i++)
        {
            string local;
            cin >> local;
            board[local.at(0) - 'a' + 2][local.at(1) - '1' + 2] = -1;
        }

        string beg1, end1;
        cin >> beg1;
        cin >> end1;
        xend = end1.at(0) - 'a' + 2;
        yend = end1.at(1) - '1' + 2;

        point p1;
        p1.x = beg1.at(0) - 'a' + 2;
        p1.y = beg1.at(1) - '1' + 2;

        p1.number = 0;
        q1.push(p1);

        jump();

        if (board[xend][yend] == 0)
            cout << "Board " << k << ":not reachable" << endl;
        else
            cout << "Board " << k << ":" << board[xend][yend] << " moves" << endl;

        init();
        cin >> b;
        k++;
    }
    return 0;
}

void jump()
{
    while (!q1.empty())
    {
        point p0 = q1.front();
        q1.pop();
        point p1;
        p1.x = p0.x - 1;
        p1.y = p0.y - 2;
        p1.number = p0.number + 1;
        if (board[p1.x][p1.y] == 0)
        {

            board[p1.x][p1.y] = p1.number;
            q1.push(p1);
        }
        p1.x = p0.x - 1;
        p1.y = p0.y + 2;
        if (board[p1.x][p1.y] == 0)
        {

            board[p1.x][p1.y] = p1.number;
            q1.push(p1);
        }
        p1.x = p0.x + 1;
        p1.y = p0.y - 2;
        if (board[p1.x][p1.y] == 0)
        {

            board[p1.x][p1.y] = p1.number;
            q1.push(p1);
        }
        p1.x = p0.x + 1;
        p1.y = p0.y + 2;
        if (board[p1.x][p1.y] == 0)
        {

            board[p1.x][p1.y] = p1.number;
            q1.push(p1);
        }
        p1.x = p0.x - 2;
        p1.y = p0.y - 1;
        if (board[p1.x][p1.y] == 0)
        {

            board[p1.x][p1.y] = p1.number;
            q1.push(p1);
        }
        p1.x = p0.x - 2;
        p1.y = p0.y + 1;
        if (board[p1.x][p1.y] == 0)
        {

            board[p1.x][p1.y] = p1.number;
            q1.push(p1);
        }
        p1.x = p0.x + 2;
        p1.y = p0.y - 1;
        if (board[p1.x][p1.y] == 0)
        {

            board[p1.x][p1.y] = p1.number;
            q1.push(p1);
        }
        p1.x = p0.x + 2;
        p1.y = p0.y + 1;
        if (board[p1.x][p1.y] == 0)
        {

            board[p1.x][p1.y] = p1.number;
            q1.push(p1);
        }
    }
}
