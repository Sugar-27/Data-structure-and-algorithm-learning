class Solution {
public:
    // 计数（统计）类的分治问题
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        // 记忆化，避免计算重复的generateParenthesis(n)
        if (h.find(n) != h.end()) return h[n];
        // 划分子问题标准：第一个子问题，作为不可分割的整体
        // 分段方法：(a)b
        // (a)： k对括号，子问题a是k-1对括号
        // b： n-k对括号
        vector<string> result;
        // 不同的k之间：加法原理
        for (int k = 1; k <= n; k++) {
            vector<string> result_a = generateParenthesis(k - 1);
            vector<string> result_b = generateParenthesis(n - k);
            // 左右两个子问题：乘法原理
            for (string& a : result_a)
                for (string& b : result_b)
                    result.push_back("(" + a + ")" + b);
        }
        h[n] = result;
        return result;
    }

private:
    unordered_map<int, vector<string>> h;

    // (a)b
    // ((())) 拆为 a=(())  b=""
    // (())() 拆为 a=()  b=()
    // ()()() 拆为 a=""  b=()()
};