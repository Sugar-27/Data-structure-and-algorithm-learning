class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        return check(s, 0, n - 1, 0);
    }
private:
    bool check(string& s, int l, int r, int cnt) {
        if (cnt >= 2) return false;
        if (l >= r) return true;
        if (s[l] == s[r]) return check(s, l + 1, r - 1, cnt);
        return check(s, l + 1, r, cnt + 1) || check(s, l, r - 1, cnt + 1);
    }
};