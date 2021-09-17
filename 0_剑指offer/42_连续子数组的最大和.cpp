class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        sums = vector<int> (n + 1, 0);
        minSum = vector<int> (n + 1, 1e9); // 存sum[i]之前最小的sum[j]
        nums.insert(nums.begin(), 0);
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
            minSum[i] = min(minSum[i - 1], sums[i - 1]);
        }
        int ans = -1e9;
        for (int i = 1; i < sums.size(); ++i) {
            ans = max(ans, sums[i] - minSum[i]);
        }
        return ans;
    }
private:
    vector<int> sums;
    vector<int> minSum;
};