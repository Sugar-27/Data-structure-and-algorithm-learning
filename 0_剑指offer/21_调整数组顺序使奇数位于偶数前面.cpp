class Solution {
   public:
    vector<int> exchange(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & 1) {
                swap(nums[idx++], nums[i]);
            }
        }
        return nums;
    }
};