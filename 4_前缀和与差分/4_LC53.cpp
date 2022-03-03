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

// 补充动态规划做法（动态规划）
// 和股票的题很像，只要出现值使得前面的和是负的那么就直接不要了
// 因为只要是负数对后面的影响都是不好的
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, ans = INT_MIN;
        for (int& n : nums) {
            pre = max(pre + n, n);
            ans = max(pre, ans);
        }
        return ans;
    }
};