// Problem : Unique Paths
// Platform : Code Studio
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define MOD 1000000007
#define PI 3.14
using namespace std;
// Recursion -> 2^(n+m)
int solve(int n, int m)
{
    if (n <= 0 or m <= 0)
    {
        return 0;
    }
    if (n == 1 or m == 1)
    {
        return 1;
    }
    return solve(n - 1, m) + solve(n, m - 1);
}
// Memorization -> n*m
int solveMem(int n, int m, vector<vector<int>> &dp)
{
    if (n <= 0 or m <= 0)
    {
        return 0;
    }
    if (n == 1 or m == 1)
    {
        return 1;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    return dp[n][m] = solveMem(n - 1, m, dp) + solveMem(n, m - 1, dp);
}
// Tabulation -> n*m
int solveTab(int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n][m];
}
int uniquePaths(int m, int n)
{
    // return solve(n,m);
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // return solveMem(n,m,dp);
    return solveTab(n, m);
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        cout << uniquePaths(m, n) << endl;
    }
    return 0;
}