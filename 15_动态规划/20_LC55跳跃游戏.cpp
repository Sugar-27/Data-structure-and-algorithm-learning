
// 贪心
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int right = 0;  // right表示目前可以到达的最远位置
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i <= right) {
                // 只有i比right小才说明i可以到达，可以到达才可以更新可到达的最远位置
                right = max(right, i + nums[i]);
            }
            if (right >= n - 1)
                return true;
        }
        return false;
    }
};