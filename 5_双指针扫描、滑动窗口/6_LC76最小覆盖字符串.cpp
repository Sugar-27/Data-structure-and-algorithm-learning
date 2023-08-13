// 双指针
// 用两个哈希表来存s和t的字符分布情况
class Solution {
  public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        unordered_map<char, int> ht;
        unordered_map<char, int> hs;
        for (char ch : t)
            ht[ch]++;
        int cnt = 0;
        int begin = 0, length = 0;
        for (int l = 0, r = 0; r < s.length(); ++r) {
            hs[s[r]]++;
            // 用来检测是否能够构成t，当cnt大小与t.length()相等时即匹配成功
            // 对于t中没有出现的元素，ht[s[i]]均为0因此hs[s[i]]一定是更大的
            // 对于t中出现的元素，只要s[i]等于了，就匹配上了，因为不要去数量相等，只要求t的字符在字串中都出现
            if (hs[s[r]] <= ht[s[r]])
                ++cnt;
            // 这个时候l是冗余的，包括不在t里的字符也都是冗余的，
            // 比如对于s：abcde，t：cd
            // l是1即s[l]是b时，hs[s[l]] = 1，ht[s[l]] = 0，继续移动左指针
            while (hs[s[l]] > ht[s[l]]) {
                hs[s[l]]--;
                ++l;
            }
            if (cnt == t.length()) {
                if (length == 0 || length > r - l + 1) {
                    begin = l;
                    length = r - l + 1;
                }
            }
        }
        return s.substr(begin, length);
    }
};