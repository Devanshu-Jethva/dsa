#include <bits/stdc++.h>
using namespace std;
#define long long ll

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char direction[] = {'L', 'R', 'U', 'D'};

bool isSafe(vector<vector<int>> &m, int &n, int i, int j, vector<vector<bool>> &visited)
{

    if ((i >= 0 && i < n) && (j >= 0 && j < n) && (m[i][j] == 1) && (visited[i][j] == false))
    {
        return true;
    }
    return false;
}

void solveMaze(vector<vector<int>> &arr, int &n, int i, int j, vector<string> &path,
               string output, vector<vector<bool>> &visited)
{

    // base case
    if (i == n - 1 && j == n - 1)
    {
        path.push_back(output);
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int newx = i + dx[k];
        int newy = j + dy[k];
        char newc = direction[k];
        if (isSafe(arr, n, newx, newy, visited))
        {
            visited[newx][newy] = true;
            solveMaze(arr, n, newx, newy, path, output + newc, visited);
            visited[newx][newy] = false;
        }
    }
}

int main()
{

    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    // assuming array is n*n
    int n = maze.size();

    vector<string> path;

    if (maze[0][0] == 0)
    {
        cout << "not path exists" << endl;
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;
    string output = "";

    solveMaze(maze, n, 0, 0, path, output, visited);

    for (auto i : path)
    {
        cout << i << endl;
    }

    return 0;
}