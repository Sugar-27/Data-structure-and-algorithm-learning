class Solution {
   public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0, right = 0;
        for (int i = 0; i < nums.size(); ++i) {
            left = max(left, nums[i]);
            right += nums[i];
        }
        while (left < right) {
            int mid = (left + right) / 2;
            if (isValid(nums, m, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

   private:
    bool isValid(vector<int>& nums, int m, int T) {
        int groupSum = 0;
        int groupCount = 1;
        for (int i = 0; i < nums.size(); i++) {
            //贪心算法，找到一个数组里能存放最多的元素
            //比如，[1,2,3,4,5], T = 8
            //[1,2,3,4], sum = 10,超了，拿出来最后一个新开一组
            //[1,2,3], [4,5], 第二组sum = 9, 没超，一共两组，跟m比较
            if (groupSum + nums[i] <= T) {
                groupSum += nums[i];
            } else {
                ++groupCount;
                groupSum = nums[i];
            }
        }
        return groupCount <= m;
    }
};