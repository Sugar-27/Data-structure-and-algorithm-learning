// 子集递归模板题

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        findSubsets(nums, 0);
        return ans;
    }

    //递归去枚举nums[0], nums[1], ..., nums[n - 1]这n个数选或者不选
    void findSubsets(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }
        // 不选（0）
        findSubsets(nums, index + 1);

        // 选（1）
        temp.push_back(nums[index]);
        findSubsets(nums, index + 1);
        temp.pop_back();
    }

private:
    vector<vector<int>> ans;
    vector<int> temp;
};