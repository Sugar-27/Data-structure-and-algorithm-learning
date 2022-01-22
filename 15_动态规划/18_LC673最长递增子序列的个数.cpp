// 与LC300很像
// 在LC300的基础上添加一个动规数组用来记录前i个数字并以nums[i]结尾的最长递增子序列个数
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> dp2(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        dp2[i] = dp2[j];
                    } else if (dp[i] == dp[j] + 1) {
                        dp2[i] += dp2[j];
                    }
                }
            }
        }
        int len = 0;
        for (int i = 0; i < dp.size(); ++i) {
            len = max(len, dp[i]);
        }
        int ans = 0;
        for (int i = 0; i < dp2.size(); ++i) {
            if (dp[i] == len)   ans += dp2[i];
        }
        return ans;
    }
};