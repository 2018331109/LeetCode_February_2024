/*
1463. Cherry Pickup II
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

    Robot #1 is located at the top-left corner (0, 0), and
    Robot #2 is located at the top-right corner (0, cols - 1).

Return the maximum number of cherries collection using both robots by following the rules below:

    From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
    When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
    When both robots stay in the same cell, only one takes the cherries.
    Both robots cannot move outside of the grid at any moment.
    Both robots should reach the bottom row in grid.

*/
#include <vector>

class Solution
{
public:
    const int N = 71;
    int n, m;
    vector<vector<vector<int>>> dp;

    int call(int r, int j1, int j2, vector<vector<int>>& grid)
    {
        if (j1 >= m || j2 >= m || j1 < 0 || j2 < 0 || r >= n)
        {
            return 0;
        }

        if (dp[r][j1][j2] != -1)
        {
            return dp[r][j1][j2];
        }

        if (r == n - 1)
        {
            return dp[r][j1][j2] = grid[r][j1] + (j1 != j2 ? grid[r][j2] : 0);
        }

        int cnt = 0;
        for (int it1 = j1 - 1; it1 <= j1 + 1; it1++)
        {
            for (int it2 = j2 - 1; it2 <= j2 + 1; it2++)
            {
                cnt = max(cnt, call(r + 1, it1, it2, grid));
            }
        }

        return dp[r][j1][j2] = cnt + grid[r][j1] + (j1 != j2 ? grid[r][j2] : 0);
    }

    int cherryPickup(vector<vector<int>>& grid)
    {
        n = grid.size();
        m = grid[0].size();
        dp.assign(N, vector<vector<int>>(N, vector<int>(N, -1)));
        int ans = call(0, 0, m - 1, grid);
        return ans;
    }
};

