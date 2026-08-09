#include <bits/stdc++.h>
using namespace std;
#define long long ll

bool isSafe(int value, int board[][9], int curr_row, int curr_col)
{
    // row check
    for (int col = 0; col < 9; col++)
    {
        if (board[curr_row][col] == value)
        {
            return false;
        }
    }

    // column check
    for (int row = 0; row < 9; row++)
    {
        if (board[row][curr_col] == value)
        {
            return false;
        }
    }

    // 3*3 box check
    for (int i = 0; i < 9; i++)
    {
        if (board[3 * (curr_row / 3) + (i / 3)][3 * (curr_col / 3) + (i % 3)] == value)
        {
            return false;
        }
    }

    return true;
}

// this function returns true or false, basis on we found a solution or not
bool solve(int board[9][9], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // check for empty cell
            if (board[i][j] == 0)
            {
                // try filling value ranging from 1 to 9
                for (int value = 1; value <= 9; value++)
                {
                    // check if safe
                    if (isSafe(value, board, i, j))
                    {
                        // insert
                        board[i][j] = value;
                        // baki recursion sambhal lega
                        bool aageKaSolution = solve(board, n);
                        if (aageKaSolution == true)
                        {
                            return true;
                        }
                        // backtracking
                        board[i][j] = 0;
                    }
                }
                // if 1 to 9 badi value current cell [i,j] par mukine try kari lidi ne solution nai maltu
                // that means pachal kyak value mukvama bhul thai chhe, go back by return false
                return false;
            }
        }
    }
    // all cell are filled so return true
    return true;
}

int main()
{
    // 0 -> empty cell

    int board[9][9] = {{4, 5, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 2, 0, 7, 0, 6, 3, 0},
                       {0, 0, 0, 0, 0, 0, 0, 2, 8},
                       {0, 0, 0, 9, 5, 0, 0, 0, 0},
                       {0, 8, 6, 0, 0, 0, 2, 0, 0},
                       {0, 2, 0, 6, 0, 0, 7, 5, 0},
                       {0, 0, 0, 0, 0, 0, 4, 7, 6},
                       {0, 7, 0, 0, 4, 5, 0, 0, 0},
                       {0, 0, 8, 0, 0, 9, 0, 0, 0}};

    int n = 9;

    solve(board, n);

    cout << "Printing solution" << endl;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
