// 新做法：使用stringstream来进行字符串切割，适用于' '分割的字符串
class Solution {
public:
    string reverseWords(string message) {
        stringstream ss(message);
        string s;
        vector<string> v;
        while (ss >> s) {
            v.push_back(s);
        }
        string ans;
        for (auto it = v.rbegin(); it != v.rend(); ++it) {
            ans.append(*it);
            ans.push_back(' ');
        }
        if (!ans.empty())
            ans.pop_back();
        return ans;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        remove_space(s);
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length();) {
            int j = i;
            while (j < s.length() && s[j] != ' ')
                ++j;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        return s;
    }

private:
    // 移除空格，每个单词之间只保留一个空格，单词首位去除空格
    void remove_space(string& s) {
        // 快慢指针法
        int slow = 0, fast = 0;
        while (fast < s.length() && s[fast] == ' ')
            ++fast;
        for (; fast < s.length(); ++fast) {
            if (fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ' ')
                continue;
            else
                s[slow++] = s[fast];
        }
        if (slow - 1 > 0 && s[slow - 1] == ' ') {
            s.resize(slow - 1);
        } else {
            s.resize(slow);
        }
    }
};