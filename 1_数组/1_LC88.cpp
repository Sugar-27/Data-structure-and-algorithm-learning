class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int max = m + n - 1;
        while (m > 0 && n > 0) {
            if (nums2[n - 1] >= nums1[m - 1]) {
                nums1[max] = nums2[n - 1];
                --max;
                --n;
            } else {
                nums1[max] = nums1[m - 1];
                --max;
                --m;
            }
        }
        while (n > 0) {
            nums1[n - 1] = nums2[n - 1];
            --n;
        }
    }
};