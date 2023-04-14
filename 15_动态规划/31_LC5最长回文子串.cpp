class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxlen = 0, start = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i <= j; ++i) {
                if (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (j - i + 1 > maxlen) {
                        start = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
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