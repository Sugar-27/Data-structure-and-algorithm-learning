class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        if (n >= 2 && islower(word[0]) && isupper(word[1]))
            return false;
        else if (n <= 2)
            return true;
        for (int i = 2; i < n; ++i) {
            if ((islower(word[i]) && islower(word[i - 1])) || (isupper(word[i]) && isupper(word[i - 1])))
                continue;
            else {
                return false;
            }
        }
        return true;
    }
};

// 规则判断，对于每一个单词
// 1. 遇到小写字母的时候它前面最多一个大写字母
// 2. 遇到大写字母的时候它前面不应该出现小写字母
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool ck = false;
        int idx = 0;
        int n = word.size();
        while (idx < n) {
            bool ck = false;
            int cnt = 0;
            while (idx < n && word[idx] != ' ') {
                if (word[idx] >= 'a' && word[idx] <= 'z') {
                    ck = true;
                    if (cnt > 1)
                        return false;
                } else if (word[idx] >= 'A' && word[idx] <= 'Z') {
                    if (ck)
                        return false;
                    ++cnt;
                }
                ++idx;
            }
        }
        return true;
    }
};