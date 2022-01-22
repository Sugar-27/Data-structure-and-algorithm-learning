// 考虑数组[0,3,1,6,2,2,7]
// 最优化目标是递增子序列的长度最大
// 考虑其中一个子数组[0,3]
// 这个子数组再往后面递增时其实只与3有关，而与0无关，因为只要比3大就可以递增
// 因此将动态规划的数组设为dp[i]，表示前i个数中以nums[i]结尾的递增子序列长度
// 动态规划的方程也就易得：dp[i] = max(dp[j] + 1)，任意选取 j < i
// 最后对动规的数组进行遍历，最大的就是最长递增子序列长度

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> f(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < f.size(); ++i) {
            ans = max(ans, f[i]);
        }
        return ans;
    }
};