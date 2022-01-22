// 动态规划，会超时
class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i * i <= n; ++i) {
            int x = i * i;
            for (int j = x; j <= n; ++j) {
                dp[j] = min(dp[j], dp[j - x] + 1);
            }
        }
        return dp[n];
    }
};

// 贪心
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int right = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i <= right) {
                right = max(right, i + nums[i]);
            }
            if (right >= n - 1)
                return true;
        }
        return false;
    }
};