#include <bits/stdc++.h>
using namespace std;

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n - queens puzzle.You may return the answer in any order.
// Each solution contains a distinct board configuration of the n -queens ' placement, where ' Q ' and '.' both
// indicate a queen and an empty space, respectively.
void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 and upperDiag[n - 1 + col - row] == 0 and lowerDiag[row + col] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiag[row + col] = 1;
            upperDiag[n - 1 + col - row] = 1;
            solve(col + 1, board, ans, leftRow, upperDiag, lowerDiag, n);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiag[row + col] = 0;
            upperDiag[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = s;

    vector<int> leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
    solve(0, board, ans, leftRow, upperDiag, lowerDiag, n);
    return ans;
}

int main()
{

    return 0;
}