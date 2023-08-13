class Solution {
   public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        stones.insert(stones.begin(), 0);
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + stones[i];
        }
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, 1e9)));
        for (int i = 0; i <= n; ++i)
            dp[i][i][1] = 0;

        for (int len = 2; len <= n; ++len) {
            for (int l = 1; l <= n - len + 1; ++l) {
                int r = l + len - 1;
                for (int i = 2; i <= k; ++i) {
                    // 这里本质上可以将dp[l][r][i]分成两个子问题
                    // 1.dp[l][p][j], 2.dp[p + 1][r][i - j]
                    // 即l~p合成j堆，以及p+1~r合成i-j堆
                    // 但事实上，这块不需要枚举j，因为不管j怎么划分结果都是一样的
                    // 只需要考虑j=1这一种情况即可，另外一堆就是i-1
                    // 也就是只考虑了第一堆在哪一段，也就是l~p是一段，后面的p+1~r合成i-1段
                    for (int p = l; p < r; ++p) {
                        dp[l][r][i] =
                            min(dp[l][r][i], dp[l][p][1] + dp[p + 1][r][i - 1]);
                    }
                }
                // 能合成一堆的前提是能合成K堆，因此也就是合成K堆的成本再加上这K堆的合
                dp[l][r][1] =
                    min(dp[l][r][1], dp[l][r][k] + sums[r] - sums[l - 1]);
            }
        }

        if (dp[1][n][1] >= 1e9)
            return -1;
        return dp[1][n][1];
    }
};