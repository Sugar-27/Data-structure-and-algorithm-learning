// 组合类题目，dfs模板题

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        phone['2'] = "abc";
        phone['3'] = "def";
        phone['4'] = "ghi";
        phone['5'] = "jkl";
        phone['6'] = "mno";
        phone['7'] = "pqrs";
        phone['8'] = "tuv";
        phone['9'] = "wxyz";
        dfs(digits, 0);
        return ans;
    }

private:
    void dfs(string& digits, int index) {
        // 终止条件
        if (index == digits.length()) {
            ans.push_back(str);
        }
        // 考虑所有出边：例如for ch in "abc"
        for (char ch : phone[digits[index]]) {
            str.push_back(ch);
            dfs(digits, index + 1);
            str.pop_back();
        }
    }
    unordered_map<char, string> phone;
    vector<string> ans;
    string str;
};