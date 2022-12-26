// 看到这种要给出方案的题，首先要想办法确定目标
// 最小括号，可以想到括号数目是有标准答案的
// 因此目标就变为了如何删可以让括号数量变成我们的目标

class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    this->s = s;
    n = s.length();
    int l = 0, r = 0; // l表示要删除的左括号，r表示要删除的右括号
    int c1 = 0, c2 = 0; // c1表示总的左括号，c2表示总的右括号
    for (char ch : s) {
      if (ch == '(')
        ++l, ++c1; // 对于左括号无脑加，只有右括号可以消除左括号
      else if (ch == ')') {
        if (l != 0)
          --l;
        else
          ++r; // 没有能跟这个右括号构成合法括号的左括号，只能删除
        ++c2;
      }
    }
    // 计算正确的答案字符串长度，这个就是我们的目标
    len = n - l - r;
    // 计算可能获得的最多的括号对数量，但可能是达不到要求的，比如对于")("，max_score是1，但只能全删了
    score_max = min(c1, c2);
    dfs(0, "", l, r, 0);
    vector<string> ans(removes.begin(), removes.end());
    return ans;
  }

private:
  void dfs(int u, string cur, int l, int r, int score) {
    // 要删除的小于零了说明删多了
    // 对于一个合法的字符串，score永远要大于等于0，即左括号的数量大于等于右括号，同时不能超过最大分数限制，超过了则没有相应的右括号能减到0
    if (l < 0 || r < 0 || score < 0 || score > score_max)
      return;
    // 要删的括号删完了
    if (l == 0 && r == 0) {
      if (cur.length() == len)
        removes.insert(cur);
    }
    // 遍历到了最后一个字符，且要删的没删完，就没必要继续了
    if (u == n)
      return;
    char c = s[u];
    if (c == '(') {
      dfs(u + 1, cur + "(", l, r, score + 1);
      dfs(u + 1, cur, l - 1, r, score);
    } else if (c == ')') {
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