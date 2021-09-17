// 与斐波那契数列完全相同思路，起始状态不相同，f(0) = 1, f(1) = 1

class Solution {
public:
    int numWays(int n) {
        int a = 1, b = 1, sum;
        for (int i = 0; i < n; ++i) {
            sum = (a + b) % (int(1e9) + 7);
            a = b;
            b = sum;
        }
        return a;
    }
};


// 记忆化递归解法
class Solution {
public:
    int numWays(int n) {
        if (n == 0) return 1;
        steps = vector<int>(n + 1, 0);
        steps[0] = 1;
        steps[1] = 1;
        return countStep(n);
    }

private:
    int countStep(int n) {
        if (steps[n] == 0) {
            steps[n] = (countStep(n - 1) + countStep(n - 2)) % (int(1e9) + 7);
            return steps[n];
        }   
        else {
            return steps[n];
        }
    }

    vector<int> steps;
};