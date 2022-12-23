// 子集是收集树形结构中树的所有节点的结果。

// 而组合问题、分割问题是收集树形结构中叶子节点的结果

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

// 全排列的思想来做
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        dfs(nums, 0);
        return ans;
    }
private:
    void dfs(vector<int>& nums, int idx) {
        ans.push_back(tmp);
        for (int i = idx; i < n; ++i) {
            tmp.push_back(nums[i]);
            dfs(nums, i + 1);
            tmp.pop_back();
        }
    }
    int n;
    vector<vector<int>> ans;
    vector<int> tmp;
};