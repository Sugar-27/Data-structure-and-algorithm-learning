class Solution {
public:
  int countSubstrings(string s) {
    int n = s.length();
    int ans = n;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i)
      dp[i][i] = true;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = (j - i + 1 <= 3) || dp[i + 1][j - 1];
          if (dp[i][j])
            ++ans;
        }
      }
    }
    return ans;
  }
};

// 中心拓展法，更快
class Solution {
public:
  int countSubstrings(string s) {
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ++ans;
      int l = i - 1, r = i + 1;
      while (l >= 0 && r < n && s[l] == s[r]) {
        ++ans;
        --l, ++r;
      }
    }
    for (int i = 0; i < n - 1; ++i) {
      int l = i, r = i + 1;
      while (l >= 0 && r < n && s[l] == s[r]) {
        ++ans;
        --l, ++r;
      }
    }
    return ans;
  }
};