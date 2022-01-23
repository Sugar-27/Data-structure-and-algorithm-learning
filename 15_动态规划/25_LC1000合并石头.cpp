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
                    for (int p = l; p < r; ++p) {
                        dp[l][r][i] =
                            min(dp[l][r][i], dp[l][p][1] + dp[p + 1][r][i - 1]);
                    }
                }
                dp[l][r][1] =
                    min(dp[l][r][1], dp[l][r][k] + sums[r] - sums[l - 1]);
            }
        }

        if (dp[1][n][1] >= 1e9)
            return -1;
        return dp[1][n][1];
    }
};