// 动态规划 + 三指针
// 每一个丑数只能由一个丑数*2或*3或*5得到，下一个丑数就是三指针中乘相应系数最小的那一个

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; ++i) {
            int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
            dp[i] = min(min(n2, n3), n5);
            if (dp[i] == n2)    a++;
            if (dp[i] == n3)   b++;
            if (dp[i] == n5)    c++;
        }
        return dp[n - 1];
    }
};
