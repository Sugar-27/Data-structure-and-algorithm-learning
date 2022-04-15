// 双指针
// 用两个哈希表来存s和t的字符分布情况
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ht;
        unordered_map<char, int> hs;
        string ans;
        for (char ch : t) {
            ht[ch]++;
        }
        int cnt = 0;
        for (int i = 0, j = 0; i < s.length(); ++i) {
            hs[s[i]]++;
            // 用来检测是否能够构成t，当cnt大小与t.length()相等时即匹配成功
            // 对于t中没有出现的元素，ht[s[i]]均为0因此hs[s[i]]一定是更大的
            // 对于t中出现的元素，只要s[i]等于了，就匹配上了，因为不要去数量相等，只要求t的字符在字串中都出现
            if (hs[s[i]] <= ht[s[i]])    cnt++;
            // 这个时候l是冗余的，包括不在t里的字符也都是冗余的，
            // 比如对于s：abcde，t：cd
            // l是1即s[l]是b时，hs[s[l]] = 1，ht[s[l]] = 0，继续移动左指针
            while (hs[s[j]] > ht[s[j]]) {
                hs[s[j]]--;
                j++;
            }
            // 只要匹配上了，cnt不会再增大，更新答案
            if (cnt == t.size()) {
                if (ans.empty() || ans.length() > i - j + 1) {
                    ans = s.substr(j, i - j + 1);
                }
            }
        }
        return ans;
    }
};