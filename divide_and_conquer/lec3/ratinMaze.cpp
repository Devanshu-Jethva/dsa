#include <bits/stdc++.h>
using namespace std;
#define long long ll

bool isSafe(int x, int y, int row, int col, int arr[][3], vector<vector<bool>> &visited)
{
    // conditions
    // 1. must be inside board - (x >= 0 && x < row) && (y >= 0 && y < col)
    // 2. must be 1 as value which indicates path - (arr[x][y] == 1)
    // 3. must be not visited - (visited[x][y] == false)
    if ((x >= 0 && x < row) && (y >= 0 && y < col) && (arr[x][y] == 1) && (visited[x][y] == false))
    {
        return true;
    }
    return false;
}

void solve(int arr[3][3], int row, int col, int i, int j, vector<vector<bool>> &visited, vector<string> &path, string output)
{

    // base case
    if (i == row - 1 && j == col - 1)
    {
        // answer found
        path.push_back(output);
        return;
    }

    // down -> i+1, j
    if (isSafe(i + 1, j, row, col, arr, visited))
    {
        visited[i + 1][j] = true;
        solve(arr, row, col, i + 1, j, visited, path, output + "D");
        // backtrack
        visited[i + 1][j] = false;
    }

    // left -> i, j-1
    if (isSafe(i, j - 1, row, col, arr, visited))
    {
        visited[i][j - 1] = true;
        solve(arr, row, col, i, j - 1, visited, path, output + "L");
        // backtrack
        visited[i][j - 1] = false;
    }

    // right -> i, j+1
    if (isSafe(i, j + 1, row, col, arr, visited))
    {
        visited[i][j + 1] = true;
        solve(arr, row, col, i, j + 1, visited, path, output + "R");
        // backtrack
        visited[i][j + 1] = false;
    }

    // up -> i-1, j
    if (isSafe(i - 1, j, row, col, arr, visited))
    {
        visited[i - 1][j] = true;
        solve(arr, row, col, i - 1, j, visited, path, output + "U");
        // backtrack
        visited[i - 1][j] = false;
    }
}

int main()
{

    int maze[3][3] = {
        {1, 0, 0},
        {1, 1, 0},
        {0, 1, 1}};

    // source par 0 apyu hoi tyare
    if (maze[0][0] == 0)
    {
        cout << "no path exists " << endl;
        return 0;
    }

    int row = 3;
    int col = 3;

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    // src value must be true
    visited[0][0] = true;

    vector<string> path;
    string output = "";

    solve(maze, row, col, 0, 0, visited, path, output);

    cout << "printing the results : " << endl;

    if (path.size() == 0)
    {
        cout << "No path exists." << endl;
        return 0;
    }

    for (auto i : path)
    {
        cout << i << endl;
    }

    return 0;
}