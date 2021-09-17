class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};
        vector<int> ans;
        int u = 0, d = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;
        while (true) {
            // 向右走
            for (int i = l; i <= r; ++i) {
                ans.push_back(matrix[u][i]);
            }
            // 改变上边界，若上边界越过下边界遍历结束
            if (++u > d)    break;
            // 向下走
            for (int i = u; i <= d; ++i) {
                ans.push_back(matrix[i][r]);
            }
            // 改变右边界，若右边界越过左边界遍历结束
            if (--r < l)    break;
            // 向左走
            for (int i = r; i >= l; --i) {
                ans.push_back(matrix[d][i]);
            }
            // 改变下边界，若下边界越过上边界遍历结束
            if (--d < u)    break;
            // 向上走
            for (int i = d; i >= u; --i) {
                ans.push_back(matrix[i][l]);
            }
            // 改变左边界，若左边界越过右边界遍历结束
            if (++l > r)    break;
        }
        return ans;
    }
};