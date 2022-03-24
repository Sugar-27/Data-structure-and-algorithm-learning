// 归并排序
// 还是要排序，可以省去很多时间
// 比如对于数组[4,3,7,2]
// 归并后，[3,4 | 2,7]，统计到3 > 2时，可以知道后面的数字比如4一定也比2大，所以ans直接+=后面的长度即可
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
private:
    int mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;
        int mid = (l + r) >> 1;
        int ans = mergeSort(nums, l, mid) + mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int n = r - l + 1;
        int temp[n];
        int idx = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                temp[idx++] = nums[i++];
            } else {
                temp[idx++] = nums[j++];
                ans += mid - i + 1;
            }
        }
        while (i <= mid) {
            temp[idx++] = nums[i++];
        }
        while (j <= r) {
            temp[idx++] = nums[j++];
        }
        for (int k = 0; k < n; ++k) {
            nums[l + k] = temp[k];
        }
        return ans;
    }
};