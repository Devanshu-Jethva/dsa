#include <bits/stdc++.h>
using namespace std;
#define long long ll

void printSolution(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n)
{
    // check karvanu chhe k current cell [row, col] par queen muki sakay k nai

    // check row
    int i = row, j = col;
    while (j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;
    }

    // check  upper left diagonal
    i = row;
    j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }

    // check bottom left diagonal
    i = row;
    j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i++;
        j--;
    }

    // kyay queen nai mali pachal ni side
    // eno mtlb k current position par queen muki saakse
    return true;
}

void solve(vector<vector<char>> &board, int col, int n)
{
    // base case
    if (col >= n)
    {
        printSolution(board, n);
        cout << endl;
        return;
    }

    // 1 case solve karo baki recursion sambhal lenga - col 0 ma badi row ma queen place karvanu try karvanu chhe

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // jo queen place karvi safe chhe to muki do
            board[row][col] = 'Q';
            // recursion solution lavse
            solve(board, col + 1, n);
            // backtrack for next solution
            board[row][col] = '-';
        }
    }
}

int main()
{

    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;
    // '-' -> empty cell
    // 'Q' -> Queen in the cell

    solve(board, col, n);

    return 0;
}