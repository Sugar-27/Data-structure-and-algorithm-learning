//三分
class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int lmid =
                (l + r) / 2;  //选lmid为二等分点，rmid为lmid稍加一点偏移量
            int rmid = lmid + 1;
            if (nums[lmid] < nums[rmid])
                l = lmid + 1;
            else
                r = rmid - 1;
        }
        return r;
    }
};