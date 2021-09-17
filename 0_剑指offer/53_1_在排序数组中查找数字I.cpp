// 两个二分，一个查第一个大于等于target的坐标，一个查最后一个小于等于target的坐标

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        // 查找第一个大于等于target的值
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int leftTarget = left;
        left = -1, right = nums.size() - 1;
        // 查找最后一个小于等于target的值
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        int rightTarget = left;
        return rightTarget - leftTarget + 1;
    }
};