#include <bits/stdc++.h>
using namespace std;

// int call(int row, int col, vector<vector<int>> &grid)
// {
//     int n = grid.size();
//     if (row < 0 && col < 0)
//         return 1e9;
//     if (row == n - 1)
//         return grid[n - 1][col];

//     int down = grid[row][col] + call(row + 1, col, grid);

//     int diagnol = grid[row][col] + call(row + 1, col + 1, grid);
//     return min(down, diagnol);
// }

// int call1(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
// {
//     int n = grid.size();
//     if (row < 0 && col < 0)
//         return 1e9;
//     if (row == n - 1)
//         return grid[n - 1][col];
//     if (dp[row][col] != -1)
//         return dp[row][col];
//     int down = grid[row][col] + call1(row + 1, col, grid, dp);

//     int diagnol = grid[row][col] + call1(row + 1, col + 1, grid, dp);
//     return dp[row][col] = min(down, diagnol);
// }

int main()
{
    vector<vector<int>> grid = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int n = grid.size();
    // int j = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // cout<<call1(0,0,grid,dp);
    // vector<vector<int>>dp1(n,vector<int>(n,-1));

    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = grid[n - 1][i];
    }

    for (int j = n - 2; j >= 0; j--)
    {
        for (int i = 0; i <= j; i++)
        {
            int down = dp[j + 1][i];
            int diag = dp[j + 1][i + 1];
            dp[j][i] = grid[j][i] + min(down, diag);
        }
    }

    cout<< dp[0][0];

    return 0;
}