class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // dp[0..n][0..n]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        // 1 [1 .. n] 1
        // 区间DP先枚举区间长度
        for (int len = 1; len <= n; ++len) {
            for (int l = 1; l <= n - len + 1; ++l) {
                // len = r - l + 1
                int r = len + l - 1;
                for (int p = l; p <= r; ++p) {
                    dp[l][r] =
                        max(dp[l][r], dp[l][p - 1] + dp[p + 1][r] +
                                          nums[l - 1] * nums[p] * nums[r + 1]);
                }
            }
        }
        return dp[1][n];
    }
};