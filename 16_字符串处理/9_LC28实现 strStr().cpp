// Rabin-Karp字符串哈希算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.length(), m = needle.length();
        // 需要给字符串进行插入空格，不然不好处理
        haystack.insert(haystack.begin(), ' ');
        needle.insert(needle.begin(), ' ');
        // H[0] = 0
        H.push_back(0);
        for (int i = 1; i <= n; ++i) {
            // 依次计算哈希值，每一个字串的哈希值都是前一个字串乘禁止再加上当前位
            // 这里要注意一个细节，个位不能等于0，a 代表'1'，如果从0开始，则无法区分ab和aab的哈希值
            H.push_back(H.back() * 131 + haystack[i] - 'a' + 1);
        }
        // 进制数组从1开始
        p131.push_back(1);
        unsigned int hash = 0;
        for (int i = 1; i <= m; ++i) {
            p131.push_back(p131.back() * 131);
            hash = hash * 131 + (needle[i] - 'a' + 1);
        }
        // 从最低位开始匹配，这个每一步都是O(1)的
        for (int i = m; i <= n; ++i) {
            int l = i - m + 1;
            if (calc(l, i) == hash) return l - 1;
        }
        return -1;
    }
private:
    unsigned int calc(int l, int r) {
        return H[r] - H[l - 1] * p131[r - l + 1];
    }
    // 两个要使用的数组，H是被匹配的字符串前缀字符串哈希
    vector<unsigned int> H;
    // p131是用131作为进制的进制数组，[1, 131, 131 * 131, ...]
    vector<unsigned int> p131;
};

// KMP算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        // 构造next数组，next数组是根据模版字符串创建的，默认为-1，即没有前缀能与现在构成的后缀进行匹配
        vector<int> ne(m, -1);
        // 从下标1开始构造，因为下标0一定没有前缀
        // i代表的是后缀，j代表的是前缀
        for (int i = 1, j = -1; i < m; ++i) {
            // 找到第一个pattern[i] == pattern[j + 1]的下标j
            while (j >= 0 && needle[i] != needle[j + 1]) j = ne[j];
            // 找到第一个pattern[i] == pattern[j + 1]的下标j
            if (needle[i] == needle[j + 1]) j++;
            // 得到j
            ne[i] = j;
        }
        // i是普通字符串下标，j是模版字符串下标，因为需要回退，j初始化为-1
        for (int i = 0, j = -1; i < n; ++i) {
            while (j >= 0 && haystack[i] != needle[j + 1]) j = ne[j];
            // str[i] == pattern[j + 1]匹配上了，j加1
            if (j + 1 < m && haystack[i] == needle[j + 1]) ++j;
            // j + 1 == n代表匹配完成，首字符下标为i - m + 1
            if (j + 1 == m) return i - m + 1;
        }
        return -1;
    }
};