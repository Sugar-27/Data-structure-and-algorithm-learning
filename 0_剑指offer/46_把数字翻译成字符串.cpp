// 动态规划

class Solution {
public:
    int translateNum(int num) {
        if (num < 10) return 1;
        string n = to_string(num);
        int len = n.length();
        vector<int> dp(len, 0);
        // 对于单个字符，只有一种翻译方式
        dp[0] = 1;
        // 对于可以组合的字符，判断是否合法，如果合法的话就有两种翻译方式
        dp[1] = stoi(n.substr(0, 2)) < 26 && stoi(n.substr(0, 2)) >= 10 ? 2 : 1;
        for (int i = 2; i < len; ++i) {
            // 对于后面的字符串，考虑它的数量：
            // “122”，“1”翻译方式一种，“12”翻译方式两种，“123“的时候，可以单独翻译“3”也可以一起翻译“23”
            // 翻译“3”那么就是从“12”也就是dp[1]转过来的，翻译"23“也就是从”1“转过来的，也就是dp[0]
            if (stoi(n.substr(i - 1, 2)) < 26 && stoi(n.substr(i - 1, 2)) >= 10) {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[len - 1];
    }
};