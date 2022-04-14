#include<iostream>
#include<vector>
/*

7 2 4     1 2 3
5 -1 6  -> 4 5 6
8 3 1     7 8 -1


*/
using namespace std;
int flage = 100;
//��������
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<vector<vector<int>>> path;
vector<vector<vector<int>>> ret;

void dfs(vector<vector<int>>& star, vector<vector<int>>& end, int x, int y, int num, int old)// old ��ʾ��һ���߹�����λ�� 1�� 0�� 3�� 2�� ��ʾ��������
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
        if (line < 0 || line > 2 || row < 0 || row > 2 || k == old) //y������Χ  x������Χ
        {
            sum[k] = 100;
            continue;
        }

        //�����ƶ����ͼ��
        swap(temp[line][row], temp[y][x]);

        //�ҵ��ƶ����ж��ٸ�������ָ��λ����
        for (int i = 0; i < 3; i++)  for (int j = 0; j < 3; j++) if (temp[i][j] != end[i][j]) sum[k]++;

        min_num = min(min_num, sum[k]);//�ҵ�ÿ���ƶ�����С�Ĵ���
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
        //�����ƶ���ʽ������С
        if (min_num == sum[i])
        {
            int line = y + dy[i];
            int row = x + dx[i];

            //�ƶ�ͼ��
            swap(star[line][row], star[y][x]);
            path.push_back(star);
            int old;
            if (i == 0) old = 1;
            else if (i == 1) old = 0;
            else if (i == 2) old = 3;
            else if (i == 3) old = 2;
            dfs(star, end, row, line, num + 1, old);
            path.pop_back();
            //�ָ�ͼ��
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