class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size();
        vector<vector<int>> dp(h, vector<int>(h, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < h; ++i) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for (int j = 1; j < triangle[i].size() - 1; ++j) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        int ans = INT_MAX;
        for (int i = 0; i < h; ++i) {
            ans = min(ans, dp[h - 1][i]);
        }
        return ans;
    }
};