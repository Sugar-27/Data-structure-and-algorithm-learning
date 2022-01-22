// 0-1背包问题模版题
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        for (int& n : nums) {
            sum += n;
        }
        if (sum & 1)
            return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] | dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};