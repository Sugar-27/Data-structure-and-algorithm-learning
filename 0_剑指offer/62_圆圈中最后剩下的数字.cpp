// 约瑟夫环问题
// 动态规划来做
// dp[i]表示总共i个人时最后剩的数字
// dp[1] = 0
// dp[i] = (dp[i - 1] + m) % i;

class Solution {
public:
    int lastRemaining(int n, int m) {
        int x = 0;
        for (int i = 2; i <= n; ++i) {
            x = (x + m) % i;
        }
        return x;
    }
};