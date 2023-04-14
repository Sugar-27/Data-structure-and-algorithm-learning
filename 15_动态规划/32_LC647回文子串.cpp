class Solution {
   public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i <= j; ++i) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
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