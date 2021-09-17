// 全排列模板题

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        findPer(nums, 0);
        return ans;
    }

    // 依次考虑0，1，……，n - 1位置放哪一个数
    // 从还没有用过的数中（used[i] == false）选一个放在当前位置
    void findPer(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                temp.push_back(nums[i]);
                findPer(nums, index + 1);
                temp.pop_back();
                used[i] = false;
            }
        }
    }

private:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> used;
};