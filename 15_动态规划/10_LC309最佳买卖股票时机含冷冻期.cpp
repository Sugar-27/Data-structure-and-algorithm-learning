// 标准动态规划，这个里面还考虑了每次交易时的手续费
class Solution {
   public:
    int maxProfit(vector<int>& prices) { return maxProfit(prices, 0); }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // Move prices from [0..n-1] to [1..n]
        prices.insert(prices.begin(), 0);

        // Initialize DP array
        vector<vector<vector<int>>> f(
            n + 1, vector<vector<int>>(2, vector<int>(2, -1000000000)));
        f[0][0][0] = 0;

        // DP
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= 1; j++)
                // 本题没有次数限制 for (int k = 0; k <= c; k++)
                for (int l = 0; l <= 1; l++) {
                    // 列表法，按表格转移，考虑出边
                    if (j == 0 && l == 0)
                        f[i + 1][1][0] = max(f[i + 1][1][0],
                                             f[i][j][l] - prices[i + 1] - fee);
                    if (j == 1 && l == 0)
                        f[i + 1][0][1] =
                            max(f[i + 1][0][1], f[i][j][l] + prices[i + 1]);
                    f[i + 1][j][0] = max(f[i + 1][j][0], f[i][j][l]);
                }

        // Calculate the target
        int ans = 0;
        for (int l = 0; l <= 1; l++)
            ans = max(ans, f[n][0][l]);
        return ans;
    }
};

// 优化，直接使用列表法进行转移
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // Move prices from [0..n-1] to [1..n]
        prices.insert(prices.begin(), 0);

        // Initialize DP array
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(2, -1e9)));
        dp[0][0][0] = 0;

        // DP
        for (int i = 1; i <= n; i++) {
            // dp[i][j][l]分别表示第i天，手中持有（j=1）或不持有股票（j=0），处于（l=1）或不处于冷冻期（l=0）
            dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][0][1]);
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][0] + prices[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][0][0] - prices[i]);
        }

        // Calculate the target
        int ans = 0;
        for (int l = 0; l <= 1; l++)
            ans = max(ans, dp[n][0][l]);
        return ans;
    }
};

// 优化内存空间
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // Move prices from [0..n-1] to [1..n]
        prices.insert(prices.begin(), 0);

        // Initialize DP array
        vector<vector<vector<int>>> dp(
            2, vector<vector<int>>(2, vector<int>(2, -1e9)));
        dp[0][0][0] = 0;

        // DP
        for (int i = 1; i <= n; i++) {
            // dp[i][j][l]分别表示第i天，手中持有（j=1）或不持有股票（j=0），处于（l=1）或不处于冷冻期（l=0）
            dp[i & 1][0][0] = max(dp[i - 1 & 1][0][0], dp[i - 1 & 1][0][1]);
            dp[i & 1][0][1] =
                max(dp[i - 1 & 1][0][1], dp[i - 1 & 1][1][0] + prices[i]);
            dp[i & 1][1][0] =
                max(dp[i - 1 & 1][1][0], dp[i - 1 & 1][0][0] - prices[i]);
        }

        // Calculate the target
        int ans = 0;
        for (int l = 0; l <= 1; l++)
            ans = max(ans, dp[n & 1][0][l]);
        return ans;
    }
};