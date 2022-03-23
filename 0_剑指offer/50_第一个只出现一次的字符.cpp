// 解法一：哈希表，两次遍历
// 最坏时间复杂度是O(2n)
class Solution {
public:
    char firstUniqChar(string s) {
        vector<char> record;
        unordered_map<char, bool> mp;
        for (char ch : s) {
            if (mp.find(ch) == mp.end()) {
                record.push_back(ch);
                mp[ch] = true;
            } else {
                mp[ch] = false;
            }
        }
        for (char ch : record) {
            if (mp[ch]) return ch;
        }
        return ' ';
    }
};

// 解法二：用一个vector模拟有序哈希表
// 最坏时间复杂度是O(n + 26)
class Solution {
public:
    char firstUniqChar(string s) {
        vector<char> record;
        unordered_map<char, bool> mp;
        for (char ch : s) {
            if (mp.find(ch) == mp.end()) {
                record.push_back(ch);
                mp[ch] = true;
            } else {
                mp[ch] = false;
            }
        }
        for (char ch : record) {
            if (mp[ch]) return ch;
        }
        return ' ';
    }
};