class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        s.insert(s.begin(), ' ');
        p.insert(p.begin(), ' ');
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        // p = " a*b*c"
        for (int i = 2; i <= n && p[i] == '*'; i += 2) dp[0][i] = true;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j] == '*') {
                    // 匹配0个
                    dp[i][j] = dp[i][j - 2];
                    // 匹配多个
                    if (p[j - 1] == s[i] || p[j - 1] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    if (s[i] == p[j]) dp[i][j] = dp[i - 1][j - 1];
                }
            }
        } 
        return dp[m][n];
    }
};