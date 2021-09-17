//时间复杂度O(n),空间复杂度O(n)
//还有时间复杂度O(n),空间复杂度O(1)的算法

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> record(nums.size(), 0);
        for (int num : nums) {
            if (record[num])    return num;
            record[num]++;
        }
        return 0;
    }
};