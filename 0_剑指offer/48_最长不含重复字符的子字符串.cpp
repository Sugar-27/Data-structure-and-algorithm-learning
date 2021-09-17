// 动态规划 + 哈希表
// 哈希表统计：遍历字符串s时，使用哈希表统计各字符最后一次出现的索引位置
// 此优化可节省dp列表使用的O(N)大小的额外空间
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int res = 0, temp = 0;
        for (int i = 0; i < s.length(); ++i) {
            int j = -1;
            if (mp.find(s[i]) != mp.end()) {
                j = mp[s[i]];
            }
            mp[s[i]] = i;
            temp = temp < i - j ? temp + 1 : i - j;
            res = max(res, temp);
        }
        return res;
    }
};

// 双指针（滑动窗口） + 哈希表
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)    return 0;
        int l = -1, r = 0; // l = -1是为了保证第一位可以录入
        int ans = 0;
        while (r < s.length()) {
            if (mp.find(s[r]) != mp.end()) {
                l = max(l, mp[s[r]]); // l可能在更新之前记录过
            }
            mp[s[r]] = r;
            ans = max(ans, r - l);
            ++r;
        }
        return ans;
    }
private:
    unordered_map<char, int> mp;
};