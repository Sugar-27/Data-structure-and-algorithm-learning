// 动态规划

class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4)  return n - 1;
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = max(max(2 * (i - 2), 2 * dp[i - 2]), max(3 * (i - 3), 3 * dp[i - 3]));
        }
        return dp[n];
    }
};

// 数学方法
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4) return n - 1;
        int a = n / 3;
        int b = n % 3;
        if (b == 0) return myPow(3, a);
        else if (b == 1) return myPow(3, a - 1) * 4;
        else return myPow(3, a) * 2;
    }

private:
    int myPow(int x, int n) {
        if (n == 0) return 1;
        int temp = myPow(x, n / 2);
        if (n % 2 == 0) return temp * temp;
        else return temp * temp * x;
    }
};