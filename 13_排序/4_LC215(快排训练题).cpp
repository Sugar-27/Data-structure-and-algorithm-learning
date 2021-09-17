//本质也是排序的模板题

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 第K大，等于（排序后下标从0开始）第N-K小
        return quickSort(nums, nums.size() - k, 0, nums.size() - 1);
    }

private:
    int quickSort(vector<int>& nums, int k, int l, int r) {
        if (l == r) return nums[l];
        int pivot = partition(nums, l, r);
        if (pivot >= k) return quickSort(nums, k, l, pivot);
        else return quickSort(nums, k, pivot + 1, r);
    }

    int partition(vector<int>& a, int l, int r) {
        int pivot = l + rand() % (r - l + 1);
        int pivotVal = a[pivot];

        while (l <= r) {
            while (a[l] < pivotVal) l++;
            while (a[r] > pivotVal) r--;
            if (l <= r) {
                int temp = a[l]; a[l] = a[r]; a[r] = temp;
                l++; r--;
            }
        }

        return r;
    }
};