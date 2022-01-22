// 基本动规
class Solution {
   public:
    int climbStairs(int n) {
        if (n < 3)
            return n;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// 空间优化
class Solution {
   public:
    int climbStairs(int n) {
        if (n < 3)
            return n;
        vector<int> dp(3, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];
        }
        return dp[n % 3];
    }
};