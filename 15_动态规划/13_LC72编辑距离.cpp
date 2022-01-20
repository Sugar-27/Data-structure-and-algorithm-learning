// 考虑word1的前i个字符变成word2的前j个字符所需要的最少编辑次数
// 其中，dp[i][0]就是删除i个字符，dp[0][j]就是添加j个字符，初始化时直接设定好
// 然后dp[i][j]，就是在删除、添加以及(修改或者不动)中选择编辑次数最少的
class Solution {
   public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        word1 = " " + word1;
        word2 = " " + word2;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= n; ++j)
            dp[0][j] = j;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = min(dp[i - 1][j] + 1,
                               min(dp[i][j - 1] + 1,
                                   dp[i - 1][j - 1] + (word1[i] != word2[j])));
            }
        }
        return dp[m][n];
    }
};