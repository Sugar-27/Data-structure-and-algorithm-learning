class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i * i <= n; ++i) {
            // 从1开始搜索，依次找1 4 9 ...
            // 最多搜索也就是i * i = n，即n本身就是一个完全平方数
            int x = i * i;
            for (int j = x; j <= n; ++j) {
                // 对于j来说，可以由j - x转移而来，转移需要加上一个完全平方数x，因此加一
                dp[j] = min(dp[j], dp[j - x] + 1);
            }
        }
        return dp[n];
    }
};