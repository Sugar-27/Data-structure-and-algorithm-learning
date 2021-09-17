class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (nums[left] == nums[right] && left != right) {
            ++left;
        }
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[right];
    }
};