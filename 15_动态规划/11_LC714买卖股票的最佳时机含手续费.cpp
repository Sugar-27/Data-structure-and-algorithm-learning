class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        vector<vector<int>> dp(2, vector<int>(2, -1e9));
        dp[0 & 1][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i & 1][0] = max(dp[i - 1 & 1][0], dp[i - 1 & 1][1] + prices[i]);
            dp[i & 1][1] =
                max(dp[i - 1 & 1][1], dp[i - 1 & 1][0] - prices[i] - fee);
        }
        return dp[n & 1][0];
    }
};