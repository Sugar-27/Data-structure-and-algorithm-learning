// dfs应用：全排列模板+合法性检查

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        used = vector<bool> (n, false);
        // dfs，排列模板 + 合法性检查
        find (0);
        // 处理数组成为字符串
        // 把排列变成.Q..的形式输出
        vector<vector<string>> result;
        for (vector<int> nums : ans) {
            vector<string> res;
            for (int num : nums) {
                string str(n, '.'); // n个.
                str[num] = 'Q';
                res.push_back(str);
            }
            result.push_back(res);
        }
        return result;
    }

private:
    void find(int row) {
        if (row == n) {
            // 调试
            // for (int x : solve) cout << x;
            // cout << endl;
            ans.push_back(solve);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (!used[col] && !plus[row + col] && !minus[row - col]) {
                used[col] = true;
                solve.push_back(col);
                minus[row - col] = true;
                plus[row + col] = true;
                find(row + 1);
                solve.pop_back();
                minus[row - col] = false;
                plus[row + col] = false;
                used[col] = false;
            }
        }
    }
    int n;
    vector<vector<int>> ans;
    vector<int> solve;
    vector<bool> used;
    unordered_map<int, bool> plus;
    unordered_map<int, bool> minus;
};

// 关于如何判断是否在同一斜线上，看i+j和i-j是否相同
/*
i+j
i-j


i-j=0
\
(1,1)
(2,2)
(3,3)
(4,4)

i-j=-1
(1,2)
(2,3)
(3,4)

i+j=5
/
(1,4)
(2,3)
(3,2)
(4,1)
*/