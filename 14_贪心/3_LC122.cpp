// 本质就是在获取所有上涨区间的差值
// 获取所有上涨区间的利润

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 0; i + 1 < prices.size(); ++i) {
            ans += max(prices[i + 1] - prices[i], 0);
        }
        return ans;
    }
};