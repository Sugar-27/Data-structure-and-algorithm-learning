class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        n = s.length();
        int l = 0, r = 0; // l表示要删除的左括号，r表示要删除的右括号
        int c1 = 0, c2 = 0; // c1表示总的左括号，c2表示总的右括号
        for (char ch : s) {
            if (ch == '(')  ++l, ++c1;
            else if (ch == ')') {
                if (l != 0) --l;
                else ++r;
                ++c2;
            }
        }
        len = n - l - r;
        score_max = min(c1, c2); // 计算最大的分数，一对完整的括号积一分
        dfs(0, "", l, r, 0);
        vector<string> ans;
        for (string k : removes) {
            ans.push_back(k);
        }
        return ans;
    }
private:
    void dfs(int u, string cur, int l, int r, int score) {
        // 要删除的小于零了说明删多了
        // 对于一个合法的字符串，score永远要大于等于0，即左括号的数量大于等于右括号，同时不能超过最大分数限制，超过了则没有相应的右括号能减到0
        if (l < 0 || r < 0 || score < 0 || score > score_max) return;
        // 要删的括号删完了
        if (l == 0 && r == 0) {
            if (cur.length() == len)    removes.insert(cur);
        }
        // 遍历到了最后一个字符，且要删的没删完，就没必要继续了
        if (u == n) return;
        char c = s[u];
        if (c == '(') {
            dfs(u + 1, cur + "(", l, r, score + 1);
            dfs(u + 1, cur, l - 1, r, score);
        }
        else if (c == ')') {
            dfs(u + 1, cur + ")", l, r, score - 1);
            dfs(u + 1, cur, l, r - 1, score);
        } else {
            dfs(u + 1, cur + c, l, r, score);
        }
    }
    unordered_set<string> removes;
    int n, len, score_max;
    string s;
};