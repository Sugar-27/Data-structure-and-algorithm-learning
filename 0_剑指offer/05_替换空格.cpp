// C++特性
// 先构造答案，遍历s

class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for (auto ch : s) {
            if (ch == ' ') {
                ans += "%20";
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};