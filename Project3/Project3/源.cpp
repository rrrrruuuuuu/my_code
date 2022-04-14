#include<iostream>
#include<vector>
/*

7 2 4     1 2 3
5 -1 6  -> 4 5 6
8 3 1     7 8 -1


*/
using namespace std;
int flage = 100;
//上下左右
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<vector<vector<int>>> path;
vector<vector<vector<int>>> ret;

void dfs(vector<vector<int>>& star, vector<vector<int>>& end, int x, int y, int num, int old)// old 表示上一次走过来的位置 1， 0， 3， 2， 表示上下左右
{
    //line   y        row  x
    int sum[4] = { 0, 0, 0, 0 };
    int min_num = 999;
    vector<vector<int>> temp;
    for (int k = 0; k < 4; k++)
    {
        temp = star;
        int line = y + dy[k];
        int row = x + dx[k];
        if (line < 0 || line > 2 || row < 0 || row > 2 || k == old) //y超出范围  x超出范围
        {
            sum[k] = 100;
            continue;
        }

        //构造移动后的图像
        swap(temp[line][row], temp[y][x]);

        //找到移动后有多少个数不在指定位置上
        for (int i = 0; i < 3; i++)  for (int j = 0; j < 3; j++) if (temp[i][j] != end[i][j]) sum[k]++;

        min_num = min(min_num, sum[k]);//找到每次移动后最小的代价
    }
    if (min_num == 0)
    {
        cout << "ds f" << endl;
        if (flage > num + 1)
        {
            ret = path;
            flage = num + 1;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        //这种移动方式代价最小
        if (min_num == sum[i])
        {
            int line = y + dy[i];
            int row = x + dx[i];

            //移动图像
            swap(star[line][row], star[y][x]);
            path.push_back(star);
            int old;
            if (i == 0) old = 1;
            else if (i == 1) old = 0;
            else if (i == 2) old = 3;
            else if (i == 3) old = 2;
            dfs(star, end, row, line, num + 1, old);
            path.pop_back();
            //恢复图像
            swap(star[line][row], star[y][x]);
        }
    }
}

int
main() {
    //vector<vector<int>> star{ {2, 8 ,3}, {1, -1, 4}, {7, 6, 5} };
    vector<vector<int>> star{ {1, 2, 3}, {8, 6, 4}, {-1, 7 ,5} };
    vector<vector<int>> end{ {1, 2, 3}, {8, -1, 4}, {7, 6, 5} };
    int x, y;
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (star[i][j] == -1) { y = i, x = j; };
    dfs(star, end, x, y, 0, 4);
    cout << flage << endl;
    return 0;
}