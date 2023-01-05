class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        //开始位置：lower_bound,查询第一个>=target的数
        //范围[0 ... n-1] + [n表示不存在]
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            //二分的单调性是基于条件的，只要条件是单调的就可以使用二分
            if (nums[mid] >= target) {  
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans.push_back(right);

        //结束位置：查询最后一个<=target的数
        //范围[-1表示不存在] + [0 ... n - 1]
        left = -1, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        ans.push_back(right);
        if (ans[0] > ans[1])
            ans = {-1, -1};
        return ans;
    }
};