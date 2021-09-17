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