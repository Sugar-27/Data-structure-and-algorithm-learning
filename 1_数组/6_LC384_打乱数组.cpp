// 打乱数组
// 一道洗牌算法模版题
// 给定一个大小为n的数组nums，对里面的数进行无规则洗牌
// nums的坐标为[0, 1, ..., n - 1]
// 题目可以理解为从原数组中随机选择数字依次填入坐标[0, n - 1]
// 换言之，可以在原数组上操作，遍历[0, n - 1]的数字，随机选择[0, n -
// 1]中的一个坐标的值与它交换 对所有位置都这样处理过后得到一个公平的洗牌方案

class Solution {
   public:
    Solution(vector<int>& nums) {
        // 初始化数组，记录原始数据
        num = nums;
        n = nums.size();
    }

    vector<int> reset() {
        // 返回原始数据即可
        return num;
    }

    vector<int> shuffle() {
        vector<int> ans = num;
        for (int i = 0; i < n; ++i) {
            // 从[0, n - 1]中随机选择一个坐标
            int index = rand() % (n);
            if (index != i)
                // 如果随机选择的坐标不是原坐标则进行交换
                swap(ans[i], ans[index]);
        }
        return ans;
    }

   private:
    vector<int> num;
    int n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */