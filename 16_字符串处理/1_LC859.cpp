// 分两种情况讨论
// 1. s 与 goal相同，如果s中存在重复元素，则交换重复元素可构成亲密字符，返回true，否则返回false;
// 2. s 与 goal不相同，如果长度不相等，直接返回false;
// 长度相等则记录s中不同元素的坐标，根据题意，s与goal不同的元素只可以存在两个，因此如果记录的不同元素坐标数量大于2或小于2，返回false;
// 如果等于2，判断交换后的s是否与goal相等，相等返回true否则返回false。

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        if (s == goal) {
            unordered_map<int, int> mp;
            for (char ch : s) {
                if (mp[ch] == 1)
                    return true;
                mp[ch]++;
            }
            return false;
        } else {
            vector<int> diff;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] != goal[i]) {
                    if (diff.size() == 2)
                        return false;
                    diff.push_back(i);
                }
            }
            if (diff.size() == 1)
                return false;
            swap(s[diff[0]], s[diff[1]]);
            return s == goal;
        }
        // return false;
    }
};