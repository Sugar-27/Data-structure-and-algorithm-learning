// 动态规划

class Solution {
public:
    int translateNum(int num) {
        string n = to_string(num);
        int len = n.length();
        if (len <= 1) return len;
        vector<int> dp(len, 0);
        dp[0] = 1;
        dp[1] = stoi(n.substr(0, 2)) < 26 && stoi(n.substr(0, 2)) >= 10 ? 2 : 1;
        cout << dp[1] << endl;;
        for (int i = 2; i < len; ++i) {
            if (stoi(n.substr(i - 1, 2)) < 26 && stoi(n.substr(i - 1, 2)) >= 10) {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[len - 1];
    }
};