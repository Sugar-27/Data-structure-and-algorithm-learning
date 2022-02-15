#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 详细思路版：
void merge(vector<int>& nums, int left, int mid, int right);
void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    //继续划分子区间，分别对左右子区间进行排序
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    //开始归并两边数据
    merge(nums, left, mid, right);
}

void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> tmp(right - left + 1);  //临时数组存合并后的有序序列
    // left为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    // mid+1为第2有序区第1个元素，j指向第1个元素
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        //较小的先存入temp中
        tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
    }
    while (i <= mid) {
        //若比较完之后，第一个有序区仍有剩余，则直接复制到temp数组中
        tmp[k++] = nums[i++];
    }
    while (j <= right) {
        //若比较完之后，第二个有序区仍有剩余，则直接复制到temp数组中
        tmp[k++] = nums[j++];
    }
    //将排好序的存回array中left到right这区间
    for (i = left, k = 0; i <= right;) {
        nums[i++] = tmp[k++];
    }
}

// 简洁版：
void mergeSort2(vector<int>& nums, int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    mergeSort2(nums, l, mid);
    mergeSort2(nums, mid + 1, r);
    // 使用数组，速度快非常多，大概是使用vector的两倍
    int n = r - l + 1;
    int temp[n];
    int i = l, j = mid + 1, idx = 0;
    while (i <= mid && j <= r) {
        temp[idx++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
    }
    while (i <= mid)
        temp[idx++] = nums[i++];
    while (j <= r)
        temp[idx++] = nums[j++];
    for (int i = 0; i < n; ++i) {
        nums[l + i] = temp[i];
    }
}

int main() {
    vector<int> nums = {3, 2, 4, 5, 6, 2, 9, 12, 1};
    // vector<int> nums2 = {3, 2, 4, 5, 6, 2, 9, 12, 1};
    for (auto& num : nums)
        cout << num << ' ';
    cout << endl;
    mergeSort2(nums, 0, nums.size() - 1);
    for (auto& num : nums)
        cout << num << ' ';
    cout << endl;
}