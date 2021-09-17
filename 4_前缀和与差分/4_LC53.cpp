//前缀和加记忆化最小前缀和

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        vector<int> minSum(n + 1, 1e9);  //存sum[i]之前最小的sum[j]
        nums.insert(nums.begin(), 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + nums[i];
            minSum[i] = min(minSum[i - 1], sum[i - 1]);
        }
        int ans = -1e9;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, sum[i] - minSum[i]);
        }
        return ans;
    }
};