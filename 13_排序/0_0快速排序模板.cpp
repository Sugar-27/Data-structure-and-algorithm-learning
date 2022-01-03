#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
int partition(vector<int>& a, int l, int r);
void quickSort(vector<int>& array, int l, int r) {
    if (l >= r)
        return;
    int pivot = partition(array, l, r);
    quickSort(array, l, pivot);
    quickSort(array, pivot + 1, r);
}

int partition(vector<int>& a, int l, int r) {
    int pivot = l + rand() % (r - l + 1);
    int pivotVal = a[pivot];

    while (l <= r) {
        while (a[l] < pivotVal)
            ++l;
        while (a[r] > pivotVal)
            --r;
        if (l == r)
            break;
        if (l < r) {
            int temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            ++l;
            --r;
        }
    }
    return r;
}
*/

void quickSort(vector<int>& nums, int l, int r) {
    if (l >= r)
        return;
    int x = nums[(l + r) >> 1];
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
    quickSort(nums, l, j);
    quickSort(nums, j + 1, r);
}

int main() {
    vector<int> nums = {3, 2, 4, 5, 6, 2, 9, 12, 1};
    // vector<int> nums2 = {3, 2, 4, 5, 6, 2, 9, 12, 1};
    for (auto& num : nums)
        cout << num << ' ';
    cout << endl;
    quickSort(nums, 0, nums.size() - 1);
    for (auto& num : nums)
        cout << num << ' ';
    cout << endl;
}