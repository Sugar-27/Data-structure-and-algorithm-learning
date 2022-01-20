// LC322 https://leetcode-cn.com/problems/coin-change/submissions/
// 从剩余零元出发，直到到达要求的金额amount
// 目标就是找的硬币数量最少，因此vector记录的数据即为找amount的钱所需要的最少硬币数量
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, (int)1e9);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] < (int)1e9 ? dp[amount] : -1;
    }
};