#include <iostream>
#include <vector>

using namespace std;

void bubSort(vector<int>& nums);
// int main() {
//     vector<int> nums = {4, 1, 5, 3, 9};
//     for (auto num : nums) {
//         cout << num << " ";
//     }
//     cout << endl;
//     bubSort(nums);
//     for (auto num : nums) {
//         cout << num << " ";
//     }
//     cout << endl;
// }

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

int main() {
    vector<int> a = {6,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};
    vector<int> b = {4,5,6,2,3,6,5,4,6,4,5,1,6,3,1,4,5,5,3,2,3,5,3,2,1,5,4,3,5,1,5};
    vector<int> c = {4,4,4,4,4,4,5,5,4,4,4,5,4,4,4,4,4,4,4,4,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,5};
    int sums = 0;
    for (int s : a) sums +=s;
    cout << sums << endl;
    cout << a.size() << endl;
    sums = 0;
    for (int s : c) sums +=s;
    cout << sums << endl;
}