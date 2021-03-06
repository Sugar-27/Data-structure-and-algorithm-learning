// 动态规划
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, -1e9)));
        dp[0][0][0] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < 2; ++j) {
                for (int m = 0; m <= 2; ++m) {
                    dp[i][j][m] = dp[i - 1][j][m];
                    if (j == 0)
                        dp[i][j][m] =
                            max(dp[i][j][m], dp[i - 1][1][m] + prices[i]);
                    else if (m > 0)
                        dp[i][j][m] =
                            max(dp[i][j][m], dp[i - 1][0][m - 1] - prices[i]);
                }
            }
        int ans = 0;
        return max(ans, max(dp[n][0][1], dp[n][0][2]));
    }
};

// 优化
// 因为交易次数是固定的，交易也只有三种情况（买、卖、不动）
// 因此可以直接分类讨论，对于每一天共有四种情况

class Solution {
    // f[i][j][k]
    // i表示当天的情况序列号
    // j表示当天买入卖出，0表示不持有股票，1表示持有股票
    // k表示当天股票持有情况，0表示还未发生买卖，1表示发生了一次买入，2表示发生了两次买入
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            2, vector<vector<int>>(2, vector<int>(3, -1e9)));
        dp[0][0][0] = 0;
        prices.insert(prices.begin(), 0);
        for (int i = 1; i <= n; ++i) {
            dp[i & 1][0][0] = dp[i - 1 & 1][0][0];
            dp[i & 1][0][1] =
                max(dp[i - 1 & 1][0][1], dp[i - 1 & 1][1][1] + prices[i]);
            dp[i & 1][0][2] =
                max(dp[i - 1 & 1][0][2], dp[i - 1 & 1][1][2] + prices[i]);
            dp[i & 1][1][1] =
                max(dp[i - 1 & 1][1][1], dp[i - 1 & 1][0][0] - prices[i]);
            dp[i & 1][1][2] =
                max(dp[i - 1 & 1][1][2], dp[i - 1 & 1][0][1] - prices[i]);
        }
        return max(0, max(dp[n & 1][0][1], dp[n & 1][0][2]));
    }
};