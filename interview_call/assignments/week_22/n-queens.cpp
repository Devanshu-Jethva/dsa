#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:

//     void storeSolution(vector<vector<char>>& board, vector<vector<string>>&
//     ans, int n) {
//         vector<string> temp;
//         for(int i=0; i<n; i++) {
//             string output = "";
//             for(int j=0; j<n; j++) {
//                 output.push_back(board[i][j]);
//             }
//             temp.push_back(output);
//         }
//         ans.push_back(temp);
//     }

//     bool isSafe(int row, int col, vector<vector<char>>& board, int n) {
//         // aa function thi check karisu k current je [row,col] chhe tya queen
//         // muki sakase k nai
//         // board ma khali left side j queens mukili hase so current column ni
//         // left side j check karvanu
//         // and check karvama left row ma, upper left half diagonally and
//         // bottom left half diagonally check karvanu
//         int i = row;
//         int j = col;

//         // check left row from [row,col]
//         while(j>=0) {
//             if(board[i][j] == 'Q') {
//                 return false;
//             }
//             j--;
//         }

//         i = row;
//         j = col;
//         // check upper left half daigonally
//         while(i>=0 && j>=0) {
//             if(board[i][j] == 'Q') {
//                 return false;
//             }
//             i--;
//             j--;
//         }

//         i = row;
//         j = col;
//         // check bottom left half daigonally
//         while(i<n && j>=0) {
//             if(board[i][j] == 'Q') {
//                 return false;
//             }
//             j--;
//             i++;
//         }

//         // left side check kari lidu pan kyay queen na mali mtlb aa position
//         safe
//         // chhe ahiya queen muki sakase to return true karo
//         return true;
//     }

//     void solve(int& n, int col, vector<vector<char>>& board,
//     vector<vector<string>>& ans) {
//         // base case
//         if(col >= n) {
//             storeSolution(board, ans, n);
//             return;
//         }

//         // 1 case solve kardo baki recursion sambhal lega
//         // current column ma badi row ma queen mukine jovanu
//         for(int row = 0; row<n; row++) {
//             if(isSafe(row,col,board,n)) {
//                 // jo queen mukvi safe chhe
//                 board[row][col] = 'Q';
//                 // recursive call mari do aagal ni column mate
//                 solve(n, col+1, board, ans);
//                 // backtrack - queen eni brbr jagya e mukai hoi k na hoi
//                 // ek column mate ek row ma queen mukine check kari lidu
//                 // have jo brbr queen place thai hoi k na hoi bada solution
//                 // kadhvana chhe to jya queen muki ti tyathi have queen
//                 remove kari
//                 // daisu ne hve column ma next row ma queen mukine aagal
//                 solution
//                 // mate explore karsu
//                 board[row][col] = '.';
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string> > ans;

//         vector<vector<char> > board(n, vector<char>(n, '.'));

//         // pehli column thi queen mukvanu chalu karsu
//         int col = 0;
//         solve(n, col, board, ans);
//         return ans;
//     }
// };

class Solution {
   public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperLeftDiagonalCheck;
    unordered_map<int, bool> bottomLeftDiagonalCheck;

    void storeSolution(vector<vector<char>>& board, vector<vector<string>>& ans,
                       int n) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string output = "";
            for (int j = 0; j < n; j++) {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<char>>& board, int n) {
        // current row ma left side check
        if (rowCheck[row]) return false;

        // current cell thi upper left diagonally check
        if (upperLeftDiagonalCheck[col - row]) return false;

        // current cell thi bottom left diagonally check
        if (bottomLeftDiagonalCheck[col + row]) return false;

        // else queen muki sakay to return true
        return true;
    }

    void solve(vector<vector<char>>& board, int col, int n,
               vector<vector<string>>& ans) {
        // base case
        if (col >= n) {
            storeSolution(board, ans, n);
            return;
        }

        for (int row = 0; row < n; row++) {
            // [row,col] e mukvu safe chhe k nai
            if (isSafe(row, col, board, n)) {
                // queen place kari and marking karyu
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftDiagonalCheck[col - row] = true;
                bottomLeftDiagonalCheck[row + col] = true;

                // recursive call
                solve(board, col + 1, n, ans);

                // backtrack
                board[row][col] = '.';
                rowCheck[row] = false;
                upperLeftDiagonalCheck[col - row] = false;
                bottomLeftDiagonalCheck[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<vector<char>> board(n, vector<char>(n, '.'));

        int col = 0;
        solve(board, col, n, ans);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}