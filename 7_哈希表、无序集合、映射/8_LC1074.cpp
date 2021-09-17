class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        sums = vector<vector<int>>(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {                
                sums[i][j] = getSum(i - 1, j) + getSum(i, j - 1) - getSum(i - 1, j - 1) + matrix[i][j];
            }
        }

        int ans = 0;
        for (int top = 0; top < m; top++) {
            for (int bot = top; bot < m; bot++) {
                int cur = 0;
                unordered_map<int, int> map;
                for (int r = 0; r < n; r++) {
                    cur = getSum(bot, r) - getSum(top - 1, r);
                    if (cur == target) ans++;
                    if (map.count(cur - target)) ans += map[cur - target];
                    map[cur]++;
                }
            }
        }
        return ans;
    }

    int getSum(int i, int j) {
        if (i < 0 || j < 0) return 0;
        else    return sums[i][j];
    }

private:
    vector<vector<int>> sums;
};