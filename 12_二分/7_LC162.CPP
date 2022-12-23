//三分
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int midl = l + r >> 1;
            int midr = midl + 1;   // 选lmid为二等分点，rmid为lmid稍加一点偏移量
            if (nums[midl] > nums[midr]) r = midr - 1;
            else l = midl + 1;
        }
        return r;
    }
};