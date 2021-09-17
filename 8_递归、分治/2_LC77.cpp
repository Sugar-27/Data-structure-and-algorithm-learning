// 组合模板题，是子集的一个特例，通过判断语句筛掉大小大于k的子集

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        findCombine(1);
        return ans;
    }

    // 枚举1，2，3，……，n这n个数要或不要
    void findCombine(int index) {
        // 选的数已经超过k个或者把剩下的数全选上依旧不够k个则停止递归
        if (temp.size() > k || temp.size() + n - index + 1 < k) return;
        if (index == n + 1) {
            if (temp.size() == k)
                ans.push_back(temp);
            return;
        }
        // 不要
        findCombine(index + 1);
        // 要
        temp.push_back(index);
        findCombine(index + 1);
        temp.pop_back();
    }

private:
    vector<vector<int>> ans;
    vector<int> temp;
    int n, k;
};