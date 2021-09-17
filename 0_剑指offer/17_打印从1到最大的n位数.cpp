class Solution {
public:
    vector<int> printNumbers(int n) {
        string str(n,'9');
        int maxNum = stoi(str);
        vector<int> ans(maxNum, 0);
        for (int i = 0; i < maxNum; ++i) {
            ans[i] = i + 1;
        }
        return ans;
    }
};