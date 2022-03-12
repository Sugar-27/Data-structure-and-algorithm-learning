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
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(k + 1, -1e9)));
        dp[0][0][0] = 0;
        prices.insert(prices.begin(), 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                // 不持有
                dp[i & 1][0][j] = max(dp[i - 1 & 1][0][j], dp[i - 1 & 1][1][j] + prices[i]);
                // 持有
                dp[i & 1][1][j] = dp[i - 1 & 1][1][j];
                if (j > 0)
                    dp[i & 1][1][j] = max(dp[i - 1 & 1][1][j], dp[i - 1 & 1][0][j - 1] - prices[i]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= k; ++i) {
            ans = max(ans, dp[n & 1][0][i]);
        }
        return ans;
    }
};