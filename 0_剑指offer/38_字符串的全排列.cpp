// 无重复的全排列问题

class Solution {
public:
    vector<string> permutation(string s) {
        used = vector<bool> (s.length(), false);
        sort(s.begin(), s.end());
        rankCh(s, 0);
        return ans;
    }
private:
    void rankCh(string& s, int index) {
        if (index == s.length()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (used[i] || (i > 0 && s[i] == s[i - 1] && !used[i - 1])) continue;
            used[i] = true;
            temp.push_back(s[i]);
            rankCh(s, index + 1);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<bool> used;
    vector<string> ans;
    string temp;
};