#include <iostream>
#include <vector>

using namespace std;

void bubSort(vector<int>& nums);
int main() {
    vector<int> nums = {4, 1, 5, 3, 9};
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    bubSort(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

void bubSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}