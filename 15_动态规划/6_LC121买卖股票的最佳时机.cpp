// 时间复杂度O(n)，非动态规划题
// 维护两个变量即可，一个是最小价格，一个是最大利润
// 保证遍历完之后的最大利润是由最大价格-最小价格就好
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 1e9, maxProfit = 0;
        for (int price : prices) {
            maxProfit = max(maxProfit, price - minPrice);
            minPrice = min(minPrice, price);
        }
        return maxProfit;
    }
};