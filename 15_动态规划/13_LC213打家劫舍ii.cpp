// 环形dp题目
// 遇到第1个与第n个状态有关的题目，进行两次dp，分开讨论
class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        nums.insert(nums.begin(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(2, -1e9));
        // 第一间屋子偷，则第n间屋子不能偷
        dp[1][0] = 0;
        dp[1][1] = nums[1];
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        int ans = dp[n][0];
        // 第一间房子不偷， 则第n间房子可以偷
        dp[1][0] = 0;
        dp[1][1] = -1e9;
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return max(ans, max(dp[n][1], dp[n][0]));
    }
};