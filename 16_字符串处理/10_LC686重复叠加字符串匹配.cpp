// 字符串哈希做法
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string aa;
        int ans = 0;
        // ans代表的是下界
        while (aa.length() < b.length() && ++ans > 0) aa.append(a);
        // aa再追加一个变成上界，如果能匹配，那么最多就是到aa，aa的长度是a.length() * (ans + 1)
        aa.append(a);
        int idx = match(aa, b);
        if (idx == -1) return -1;
        return idx + b.length() <= a.length() * ans ? ans : ans + 1;
    }
private:
    // 字符串哈希匹配
    int match(string a, string b) {
        int m = a.length(), n = b.length();
        a.insert(a.begin(), ' ');
        b.insert(b.begin(), ' ');
        vector<unsigned int> P131;
        vector<unsigned int> H;
        H.push_back(0);
        for (int i = 1; i <= m; ++i) {
            H.push_back(H.back() * 131 + a[i] - 'a' + 1);
        }
        unsigned int hash = 0;
        P131.push_back(1);
        for (int i = 1; i <= n; ++i) {
            hash = hash * 131 + b[i] - 'a' + 1;
            P131.push_back(P131.back() * 131);
        }
        for (int r = n; r <= m; ++r) {
            int l = r - n + 1;
            if (H[r] - H[l - 1] * P131[r - l + 1] == hash) {
                return l - 1;
            }
        }
        return -1;
    }
};