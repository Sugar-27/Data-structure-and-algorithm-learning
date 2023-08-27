class Solution {
public:
  int reversePairs(vector<int> &nums) {
    ans = 0;
    mergeSort(nums, 0, nums.size() - 1);
    return ans;
  }

private:
  void mergeSort(vector<int> &nums, int l, int r) {
    if (l >= r)
      return;
    int mid = (l + r) >> 1;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    calculate(nums, l, mid, r);
    merge(nums, l, mid, r);
  }
  void merge(vector<int> &nums, int l, int mid, int r) {
    vector<int> temp(r - l + 1); // 临时数组
    int left = l, right = mid + 1, k = 0;
    while (left <= mid && right <= r) { // 合并两个有序数组
      if (nums[left] <= nums[right]) {
        temp[k++] = nums[left++];
      } else {
        temp[k++] = nums[right++];
      }
    }
    while (left <= mid)
      temp[k++] = nums[left++];
    while (right <= r)
      temp[k++] = nums[right++];
    for (int i = 0; i < temp.size(); i++) { // 拷回原数组
      nums[l + i] = temp[i];
    }
  }
  void calculate(vector<int> &nums, int l, int mid, int r) { // 统计翻转对
    for (int i = l, j = mid; i <= mid; i++) {
      while (j < r && nums[i] > 2l * nums[j + 1])
        j++;
      ans += j - mid;
    }
  }
  int ans;
};

// 使用二分进行优化可以更快
class Solution {
public:
  int reversePairs(vector<int> &nums) {
    int n = nums.size();
    merge_sort(nums, 0, n - 1);
    return ans;
  }

private:
  int ans = 0;
  void merge_sort(vector<int> &nums, int l, int r) {
    if (l >= r)
      return;
    int mid = l + r >> 1;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);

    calculate(nums, l, mid, r);

    int tmp[r - l + 1];
    memset(tmp, 0, r - l + 1);
    int i = l, j = mid + 1, idx = 0;
    while (i <= mid && j <= r) {
      if (nums[i] < nums[j]) {
        tmp[idx++] = nums[i++];
      } else {
        tmp[idx++] = nums[j++];
      }
    }
    while (i <= mid)
      tmp[idx++] = nums[i++];
    while (j <= r)
      tmp[idx++] = nums[j++];

    for (int k = 0; k < r - l + 1; ++k) {
      nums[l + k] = tmp[k];
    }
  }

  void calculate(vector<int> &nums, int l, int mid, int r) { // 统计翻转对
    for (int i = l, j = mid; i <= mid; i++) {
      int a = mid, b = r;
      while (a < b) {
        int m = a + b + 1 >> 1;
        if (nums[i] > 2l * nums[m]) {
          a = m;
        } else {
          b = m - 1;
        }
      }
      ans += b - mid;
    }
  }
};