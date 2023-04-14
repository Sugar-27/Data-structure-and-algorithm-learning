class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int m = triangle.size(), n = triangle.back().size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < triangle[i].size(); ++j) {
        dp[i][j] = dp[i - 1][j];
        if (j > 0) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
        dp[i][j] += triangle[i][j];
      }
    }
    return *min_element(dp[m - 1].begin(), dp[m - 1].end());
  }
};