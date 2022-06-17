// 中心拓展法，O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int ansIdx = -1;
        int ansLen = INT_MIN;
        s.insert(s.begin(), ' ');
        // 中心是字符，比如"ababc"，以a为中心向两边拓展
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
        // 中心是空格（以竖线代替），比如字符串"ab｜ba"，以|为中心向两边拓展，依次变成bb，abba
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