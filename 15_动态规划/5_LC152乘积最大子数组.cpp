class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> fmax(nums.size() + 1, 1);
        vector<int> fmin(nums.size() + 1, 1);
        for (int i = 1; i <= nums.size(); i++) {
            fmax[i] = max(max(fmax[i - 1] * nums[i - 1], fmin[i - 1] * nums[i - 1]), nums[i - 1]);
            fmin[i] = min(min(fmax[i - 1] * nums[i - 1], fmin[i - 1] * nums[i - 1]), nums[i - 1]);
        }
        int ans = -1e9;
        for (int i = 1; i < fmax.size(); ++i) { // 需要从1开始，因为fmax[0]是边界而没有记录原来数组的乘积信息
            ans = max(ans, fmax[i]);
        }
        return ans;
    }
};