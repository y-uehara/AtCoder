#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int H, W;

    cin >> H >> W;
    vector<vector<int>> board(H, vector<int>(W));

    char c;
    list<pair<int, int>> black;

    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
        {
            cin >> c;
            if(c == '#')
            {
                board[i][j] = 0;
                black.push_back(make_pair(i, j));
            }
            else
                board[i][j] = -1;
        }

    int step = 0;
    while(!black.empty())
    {
        auto iter = black.front();
        black.pop_front();

        int x = iter.first;
        int y = iter.second;
        step = board[x][y];
        if(x-1 >= 0)
        {
            if(board[x-1][y] == -1)
            {
                board[x-1][y] = step + 1;
                black.push_back(make_pair(x-1, y));
            }
        }
        if(x+1 < H)
        {
            if(board[x+1][y] == -1)
            {
                board[x+1][y] = step + 1;
                black.push_back(make_pair(x+1, y));
            }
        }
        if(y-1 >= 0)
        {
            if(board[x][y-1] == -1)
            {
                board[x][y-1] = step + 1;
                black.push_back(make_pair(x, y-1));
            }
        }
        if(y+1 < W)
        {
            if(board[x][y+1] == -1)
            {
                board[x][y+1] = step + 1;
                black.push_back(make_pair(x, y+1));
            }
        }
    }

    cout << step << endl;
    return 0;
}