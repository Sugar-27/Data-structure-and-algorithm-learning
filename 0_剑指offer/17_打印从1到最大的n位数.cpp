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

class Solution {
public:
    vector<int> printNumbers(int n) {
        int end = 0;
        while (n != 0) {
            end = end * 10 + 9;
            --n;
        }
        cout << end << endl;
        vector<int> ans(end, 0);
        for (int i = 1; i <= end; ++i) {
            ans[i - 1] = i;
        }
        return ans;
    }
};