// 本质上就是一道有冷冻期的股票买卖题
class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(2, -1e9));
        nums.insert(nums.begin(), 0);
        dp[0 & 1][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i & 1][0] = max(dp[i - 1 & 1][0], dp[i - 1 & 1][1]);
            dp[i & 1][1] = dp[i - 1 & 1][0] + nums[i];
        }
        return max(dp[n & 1][0], dp[n & 1][1]);
    }
};