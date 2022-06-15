// 求图中任意两点之间的距离
// 使用Floyd算法
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> e(n, vector<int> (n, 1e9));
        for (int i = 0; i < n; ++i) e[i][i] = 0;
        for (auto& edge : edges) {
            int x = edge[0], y = edge[1], d = edge[2];
            e[x][y] = d;
            e[y][x] = d;
        }
        // Floyd算法模版
        // 本质是动规，k是中继节点，dp[k][i][j]表示最多以k点为中继节点时两点之间的最小距离
        // 如果不走第k个点更新方程为dp[k][i][j] = dp[k - 1][i][j]
        // 如果走第k个点更新方程为dp[k][i][j] = dp[k][i][k] + dp[k][k][j]
        // 因此可以忽略掉k这一个纬度，三维优化到二维
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
                }
            }
        }
        int ans = -1;
        int ansCount = n;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && e[i][j] <= distanceThreshold) ++cnt;
            }
            if (cnt <= ansCount) {
                ansCount = cnt;
                ans = i;
            }
        }
        return ans;
    }
};