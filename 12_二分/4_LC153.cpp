class Solution {
   public:
    int findMin(vector<int>& nums) {
        /*
            3 4 5 | 1 2
            左段：>nums[right]
            右段：<=nums[right]
            0 0 0   1 1

            4,5,6,7 | 0,1,2

            |1 2 3 4 5


            题目条件：找第一个<=末尾的数
        */
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] <=
                nums[right]) {  //二分的单调性是基于条件的，只要条件是单调的就可以使用二分
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[right];
    }
};