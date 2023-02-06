// Problem : Sudoku Solver
// Platform : LeetCode
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MOD 1e9+7
#define PI 3.14
using namespace std;
bool isSafe(vector<vector<int>>& sudoku,int row,int col,int val,int n)
{
    for(int i = 0; i < n; i++ )
    {
        // Row and Column Check
        if(sudoku[row][i] == val || sudoku[i][col]==val)
        {
            return false;
        }
        // 3X3 Check
        if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]==val)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>& sudoku)
{
    int n = sudoku.size();
    int m = sudoku[0].size();
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
            // if (Empty Slot)
            if(sudoku[row][col]==0)
            {
                // trying all possible values
                for(int val = 1; val <= 9; val++ )
                {
                    if(isSafe(sudoku,row,col,val,n))
                    {
                        sudoku[row][col] = val;
                        // Completely Solved
                        if(solve(sudoku))
                        {
                            return true;
                        }
                        // if can't be solved further then backtrack
                        else
                        {
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
    solve(sudoku);
}