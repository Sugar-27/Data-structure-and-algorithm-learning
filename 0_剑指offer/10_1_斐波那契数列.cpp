// 动态规划法，最优解

class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, sum;
        for (int i = 0; i < n; ++i) {
            sum = (a + b) % (int(1e9) + 7);
            a = b;
            b = sum;
        }
        return a;
    }
};

// 更好理解的动态规划
class Solution {
public:
    int fib(int n) {
        if (n < 2)  return n;
        int a = 0, b = 1, sum;
        for (int i = 2; i <= n; ++i) { //　i代表现在求到的n，sum是当前n的结果
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return b;
    }
};

// 记忆化+递归
class Solution {
public:
    int fib(int n) {
        if (n == 0) return n;
        fibN = vector<int>(n + 1, 0);
        fibN[1] = 1;
        return clacFib(n);
    }
private:
    int clacFib(int n) {
        if(fibN[n] == 0 && n > 0){
            fibN[n] = clacFib(n - 1) + clacFib(n - 2);
            return (fibN[n] % 1000000007);
        }
        else return (fibN[n] % 1000000007);
    }

    vector<int> fibN;
};