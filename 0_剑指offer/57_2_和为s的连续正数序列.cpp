// 滑动窗口

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int i = 1, j = 1;
        int sum = 0;
        while (i <= target / 2) {
            if (sum < target) {
                sum += j;
                j++;
            } else if (sum > target) {
                sum -= i;
                i++;
            } else {
                vector<int> res;
                for (int a = i; a < j; a++) {
                    res.push_back(a);
                }
                ans.push_back(res);
                sum -= i;
                i++;
            }
        }
        return ans;
    }
};