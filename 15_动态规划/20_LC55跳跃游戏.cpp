
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