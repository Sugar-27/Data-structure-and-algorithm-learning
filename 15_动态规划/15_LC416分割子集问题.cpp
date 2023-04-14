// 0-1背包问题模版题
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int acc = accumulate(nums.begin(), nums.end(), 0);
    if (acc & 1)
      return false;
    acc /= 2;
    vector<bool> dp(acc + 1, false);
    dp[0] = true;
    for (int num : nums) {
      for (int j = acc; j >= num; --j) {
        dp[j] = (dp[j] || dp[j - num]);
      }
    }
    return dp[acc];
  }
};