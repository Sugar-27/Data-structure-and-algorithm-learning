// 从这一题开始进入0-1背包的模版
// 本题是一道完全背包问题

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[j]表示组成j的总金额所具有的方案数
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j - coins[i] >= 0)
                    dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

// 优化
// j - coins[i]必须大于等于0即j >= coins[i]，直接从coins[i]开始遍历状态
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[j]表示组成j的总金额所具有的方案数
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};