// 从剩余零元出发，直到到达要求的金额amount
// 目标就是找的硬币数量最少，因此vector记录的数据即为找amount的钱所需要的最少硬币数量
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> opt(amount + 1, 0);
        for (int i = 1; i <= amount; ++i) {
            opt[i] = (int)1e9;
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0)
                    opt[i] = min(opt[i], opt[i - coins[j]] + 1);
            }
        }
        return opt[amount] == (int)1e9 ? -1 : opt[amount];
    }
};