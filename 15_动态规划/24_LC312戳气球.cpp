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
                    dp[l][r] = max(dp[l][r], dp[l][p - 1] + dp[p + 1][r] + 
                                             nums[l - 1] * nums[p] * nums[r + 1]);
                }
            }
        }
        return dp[1][n];
    }
};

// 记忆化搜索
// 虽然时间复杂度一样，但因为递归增加了开销，因此时间会上升
class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        reward = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return dfs(nums, 1, n);
    }

   private:
    int dfs(vector<int>& nums, int l, int r) {
        if (l > r)
            return 0;
        if (reward[l][r] >= 0)
            return reward[l][r];
        reward[l][r] = 0;
        for (int p = l; p <= r; ++p) {
            reward[l][r] =
                max(reward[l][r], dfs(nums, l, p - 1) + dfs(nums, p + 1, r) +
                                      nums[l - 1] * nums[p] * nums[r + 1]);
        }
        return reward[l][r];
    }
    vector<vector<int>> reward;
};