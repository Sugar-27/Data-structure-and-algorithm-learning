class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, i = 0;
        for (int& child : g) {
            while (i < s.size() && child > s[i]) {
                ++i;
            }
            if (i < s.size()) {
                ++ans;
                ++i;
            }
        }
        return ans;
    }
};