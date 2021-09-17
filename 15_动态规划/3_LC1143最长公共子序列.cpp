// 本题解法
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        text1 = " " + text1; // 添加一个保护边界，这样子在进行循环的时候对与i - 1与j - 1不需要进行特殊处理
        text2 = " " + text2;
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0)); // f[i][j]表示text1前i个字符与text2前j个字符的最长子序列
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i] == text2[j])   f[i][j] = f[i - 1][j - 1] + 1; // 遍历的过程中如果字符数相等则可以使得最长子序列加一
                else f[i][j] = max(f[i - 1][j], f[i][j - 1]); // 不相等的时候选择上一个最长的子序列
            }
        }
        return f[m][n];
    }
};

// 打印答案出来，需要记录操作
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        text1 = " " + text1; // 添加一个保护边界，这样子在进行循环的时候对与i - 1与j - 1不需要进行特殊处理
        text2 = " " + text2;
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0)); // f[i][j]表示text1前i个字符与text2前j个字符的最长子序列
        vector<vector<int>> operate(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i] == text2[j]){
                    f[i][j] = f[i - 1][j - 1] + 1; // 遍历的过程中如果字符数相等则可以使得最长子序列加一
                    operate[i][j] = 1;
                }
                else f[i][j] = max(f[i - 1][j], f[i][j - 1]); // 不相等的时候选择上一个最长的子序列
            }
        }
        // 打印最长子序列
        string text;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (operate[i][j] == 1) text.push_back(text1[i]);
            }
        }
        cout << text << endl;
        return f[m][n];
    }
};

// 优化：记录完整操作，使用递归进行打印，不需要遍历所有的i和j
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        text1 = " " + text1;
        text2 = " " + text2;
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> dir(n + 1, vector<int>(m + 1, 0));
        // int[][] f = new int[n + 1][m + 1];
        for (int i = 0; i <= n; i++) f[i][0] = 0;
        for (int j = 0; j <= m; j++) f[0][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (text1[i] == text2[j]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    dir[i][j] = 0;
                }
                else {
                    if (f[i - 1][j] > f[i][j - 1]) {
                        f[i][j] = f[i - 1][j];
                        dir[i][j] = 1;
                    } else {
                        f[i][j] = f[i][j - 1];
                        dir[i][j] = 2;
                    }
                }
        print(text1, dir, n, m); // 打方案（本题不用）
        cout << ans << endl;
        return f[n][m];
    }

private:
    void print(string& text1, vector<vector<int>>& dir, int i, int j) {
        if (i == 0 || j == 0) return;
        if (dir[i][j] == 0) {
            print(text1, dir, i-1, j-1);
            ans.push_back(text1[i]);
        } else if (dir[i][j] == 1) {
            print(text1, dir, i-1, j);
        } else {
            print(text1, dir, i, j-1);
        }
    }

    string ans;
};