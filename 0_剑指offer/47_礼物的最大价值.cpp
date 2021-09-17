// 动规来做，用dfs会超时

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                else if (i == 0)    dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (j == 0)    dp[i][j] = dp[i - 1][j] + grid[i][j];
                else    dp[i][j] = max(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[m - 1][n - 1];
    }
};

// 动规的原地修改算法，空间复杂度O(1)
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int> (n, 0));
        // dp[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                else if (i == 0)    grid[i][j] += grid[i][j - 1];
                else if (j == 0)    grid[i][j] += grid[i - 1][j];
                else    grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};