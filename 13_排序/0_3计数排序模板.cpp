#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void countSort(vector<int>& nums) {
    int maxVal = -1;
    for (int num : nums) {
        maxVal = max(maxVal, num);
    }

    int index = 0;  //原数组修改坐标

    vector<int> count(maxVal + 1);
    for (int num : nums) {
        ++count[num];
    }
    for (int val = 0; val < count.size(); ++val) {
        while (count[val] > 0) {
            --count[val];
            nums[index++] = val;
        }
    }
}

int main() {
    vector<int> test = {4, 5, 2, 1, 4, 2, 3, 4, 4, 0, 8};
    for (auto a : test) {
        cout << a << ' ';
    }
    cout << endl;
    countSort(test);
    for (auto a : test) {
        cout << a << ' ';
    }
    cout << endl;
}