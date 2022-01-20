// 基本动态规划
// 引入了k次交易，状态空间变大了
class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1e9)));
        dp[0][0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int m = 0; m <= k; ++m) {
                    dp[i][j][m] = dp[i - 1][j][m];
                    if (j == 0) {
                        dp[i][j][m] =
                            max(dp[i][j][m], dp[i - 1][1][m] + prices[i]);
                    } else if (j == 1 && m > 0) {
                        dp[i][j][m] =
                            max(dp[i][j][m], dp[i - 1][0][m - 1] - prices[i]);
                    }
                }
            }
        }
        int ans = 0;
        for (int m = 0; m <= k; ++m) {
            ans = max(ans, dp[n][0][m]);
        }
        return ans;
    }
};

// 优化空间复杂度，每一天的状态的值仅与前一天有关
// 因此不需要O(n)的空间复杂度，只需要O(2)的空间来记录相邻两天的变化
class Solution {
   public:
    int maxProfit(int c, vector<int>& prices) {
        int n = prices.size();
        // Move prices from [0..n-1] to [1..n]
        prices.insert(prices.begin(), 0);

        // Initialize DP array
        vector<vector<vector<int>>> f(
            2, vector<vector<int>>(2, vector<int>(c + 1, -1000000000)));
        f[0 & 1][0][0] = 0;

        // DP
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= 1; j++)
                for (int k = 0; k <= c; k++) {
                    f[i & 1][j][k] = f[(i - 1) & 1][j][k];
                    if (j == 0)
                        f[i & 1][0][k] = max(f[i & 1][0][k],
                                             f[(i - 1) & 1][1][k] + prices[i]);
                    if (j == 1 && k > 0)
                        f[i & 1][1][k] =
                            max(f[i & 1][1][k],
                                f[(i - 1) & 1][0][k - 1] - prices[i]);
                }

        // Calculate the target
        int ans = 0;
        for (int k = 0; k <= c; k++)
            ans = max(ans, f[n & 1][0][k]);
        return ans;
    }
};