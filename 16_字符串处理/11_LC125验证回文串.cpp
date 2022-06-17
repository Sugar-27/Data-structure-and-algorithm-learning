class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() < 2) return true;
        int n = s.length();
        for (int l = 0, r = n - 1; l <= r; ++l, --r) {
            while (l < n && !isalnum(s[l])) ++l;
            while (r >= 0 && !isalnum(s[r])) --r;
            if (l >= r) break;
            if (isalpha(s[l])) {
                // cout << s[l] << ' ' << s[r] << endl;
                if (tolower(s[l]) != tolower(s[r]))
                    return false;
            } else if (s[l] != s[r]) return false;
        }
        return true;
    }
};