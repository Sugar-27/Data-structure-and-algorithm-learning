// 类切片做法，时间复杂度O(n), 空间复杂度O(n)

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string str;
        for (int i = n; i < s.length(); ++i) {
            str.push_back(s[i]);
        }
        for (int i = 0; i < n; ++i) {
            str.push_back(s[i]);
        }
        return str;
    }
};

// 原地旋转做法，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};