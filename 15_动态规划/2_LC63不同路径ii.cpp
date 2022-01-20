// 记忆化搜索：dfs
// 记忆从 (0, 0) 到每一个点的路径数量，记为paths，pahts[0][0] = 1
// 每一个点的路径数量就等于paths[x - 1][y] + pahts[x][y - 1]
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        paths = vector<vector<int>> (m, vector<int> (n, 0));
        paths[0][0] = 1;
        return dfs(obstacleGrid, m - 1, n - 1);
    }
private:
    int dfs(vector<vector<int>>& obstacleGrid, int x, int y) {
        if (x < 0 || y < 0) return 0;   // 考虑边界
        if (obstacleGrid[x][y] == 1)    return 0;   // 有障碍物时就不能通过了，没有路径数
        if (paths[x][y] != 0)   return paths[x][y]; // 对于有记忆过的点直接返回即可，不需要二次搜索
        paths[x][y] = dfs(obstacleGrid, x - 1, y) + dfs(obstacleGrid, x, y - 1);    // 路径的计算方程
        return paths[x][y];
    }
    int m, n;
    vector<vector<int>> paths;
};

// 更快的做法，动态规划
// 其实本质与记忆化搜索一样，但省去了系统递归时进行堆栈记忆的时间
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));    // 动归数组，记忆路径数
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)  f[i][j] = 0;
                else if (i == 0 && j == 0) f[i][j] = 1;
                else if (i == 0)    f[i][j] = f[i][j - 1];
                else if (j == 0)    f[i][j] = f[i - 1][j];
                else f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};