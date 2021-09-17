// 简单算法，时间复杂度O(n)

class Solution {
public:
    int minArray(vector<int>& numbers) {
        for (int i = 1; i < numbers.size(); ++i) {
            if (numbers[i] >= numbers[i - 1])   continue;
            return numbers[i];
        }
        return numbers[0];
    }
};

// 二分，时间复杂度O(logn)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (nums[left] == nums[right] && left < right) {
            left++;
        }
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};