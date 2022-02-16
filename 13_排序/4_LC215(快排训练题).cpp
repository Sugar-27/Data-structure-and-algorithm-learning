//本质也是排序的模板题
#include <vector>

using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        // 第K大，等于（排序后下标从0开始）第N-K小
        quickSort(nums, 0, nums.size() - 1, k);
        return nums[nums.size() - k];
    }

   private:
    void quickSort(vector<int>& nums, int l, int r, const int& k) {
        if (l >= r)
            return;
        int x = nums[l + r >> 1];
        int i = l, j = r;
        while (i <= j) {
            while (nums[i] < x)
                ++i;
            while (nums[j] > x)
                --j;
            if (i == j)
                break;
            if (i < j)
                swap(nums[i++], nums[j--]);
        }
        if (j >= nums.size() - k)
            quickSort(nums, l, j, k);
        else {
            quickSort(nums, j + 1, r, k);
        }
    }
};