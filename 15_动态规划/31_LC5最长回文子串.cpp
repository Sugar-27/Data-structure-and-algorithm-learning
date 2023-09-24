class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    int ans_begin = 0, ans_len = 1;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i)
      dp[i][i] = true;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        int len = j - i + 1;
        if (s[i] == s[j]) {
          dp[i][j] = len <= 3 || dp[i + 1][j - 1];
          if (dp[i][j] && len > ans_len) {
            ans_begin = i;
            ans_len = len;
          }
        }
      }
    }
    return s.substr(ans_begin, ans_len);
  }
};

// 中心拓展法，更快
class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    int ansIdx = -1;
    int ansLen = INT_MIN;
    s.insert(s.begin(), ' ');
    for (int center = 1; center <= n; ++center) {
      int l = center - 1, r = center + 1;
      int len = 1;
      while (l > 0 && r <= n && s[l] == s[r]) {
        --l, ++r;
        len += 2;
      }
      if (len > ansLen) {
        ansIdx = l + 1;
        ansLen = len;
      }
    }
    for (int center = 1; center < n; ++center) {
      int l = center, r = center + 1;
      int len = 0;
      while (l > 0 && r <= n && s[l] == s[r]) {
        --l, ++r;
        len += 2;
      }
      if (len > ansLen) {
        ansIdx = l + 1;
        ansLen = len;
      }
    }
    return s.substr(ansIdx, ansLen);
  }
};