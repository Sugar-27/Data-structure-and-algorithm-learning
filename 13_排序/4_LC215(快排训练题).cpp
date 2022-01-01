//本质也是排序的模板题
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        this->k = k;
        // 第K大，等于（排序后下标从0开始）第N-K小
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }

private:
    int k;
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int pivot = partition(nums, l, r);
        if (pivot >= nums.size() - k) {
            quickSort(nums, l, pivot);
        } else {
            quickSort(nums, pivot + 1, r);
        }
    }
    int partition(vector<int>& nums, int l, int r) {
        int pivot = l + rand() % (r - l + 1);
        int pivotVal = nums[pivot];
        while (l <= r) {
            while (nums[l] < pivotVal)  ++l;
            while (nums[r] > pivotVal)  --r;
            if (r == l) break;
            if (l < r) 
                swap(nums[l++], nums[r--]);
        }
        return r;
    }
};