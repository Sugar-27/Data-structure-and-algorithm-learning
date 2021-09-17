//简洁算法
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[n++] = nums[i];
            }
        }
        return n;
    }
};

//快慢指针
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int slow = 0, fast = 1;
        while (fast < nums.size()) {
            if (nums[fast] == nums[slow]) {
                ++fast;
            } else {
                ++slow;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};