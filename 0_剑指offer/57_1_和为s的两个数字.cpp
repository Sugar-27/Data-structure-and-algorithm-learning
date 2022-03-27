class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] > target)  right--;
            else if(nums[left] + nums[right] < target) left++;
            else return{nums[left], nums[right]};
        }
        return {};
    }
};