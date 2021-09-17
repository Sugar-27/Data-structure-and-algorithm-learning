class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        findPer(nums, 0);
        return ans;
    }

    // 依次考虑0，1，……，n - 1位置放哪一个数
    // 从还没有用过的数中（used[i] == false）选一个放在当前位置
    // 保证在填第index个数的时候重复数字只会被填入一次即可
    void findPer(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            // 判断条件保证了对于重复数的集合，一定是从左往右逐个填入的
            // 这里要注意!used[i - 1]是在保证填入顺序
            // 一定是nums[i - 1]已经填过了才会填入nums[i]
            // 这样子从相同的数字nums[i]-nums[j]只会填入一次，不存在反复
            // 如两个1，分别标记为1a，1b，通过这种手段就有效保证了只有1a1b这种排列组合而没有1b1a这种排列组合
            // i > 0 保证 i - 1不会越界
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;
            }
            used[i] = true;
            temp.push_back(nums[i]);
            findPer(nums, index + 1);
            temp.pop_back();
            used[i] = false;
        }
    }

private:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> used;
};