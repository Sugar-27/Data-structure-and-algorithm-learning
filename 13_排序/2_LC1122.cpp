//计数排序的变种
class Solution {
   public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans(arr1.size());
        vector<int> count(1001);
        for (int i = 0; i < arr1.size(); ++i) {
            ++count[arr1[i]];
        }
        // 先按照arr2的顺序来取
        int index = 0;
        for (int num : arr2) {
            while (count[num] > 0) {
                --count[num];
                ans[index++] = num;
            }
        }
        // 再按照正常顺序处理未在arr2中出现过的数据
        for (int i = 0; i < count.size(); ++i) {
            while (count[i] > 0) {
                --count[i];
                ans[index++] = i;
            }
        }
        return ans;
    }
};