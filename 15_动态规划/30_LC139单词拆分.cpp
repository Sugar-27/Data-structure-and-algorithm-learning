class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] && st.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[n];
  }
};

// 区间dp解法，较慢，好理解
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int len = 1; len <= n; ++len) {
      for (int l = 0; l + len - 1 < n; ++l) {
        int r = l + len - 1;
        if (st.count(s.substr(l, len))) {
          dp[l][r] = true;
        } else {
          for (int p = l; p < r; ++p) {
            dp[l][r] = dp[l][r] || (dp[l][p] && dp[p + 1][r]);
          }
        }
      }
    }
    return dp[0][n - 1];
  }
};