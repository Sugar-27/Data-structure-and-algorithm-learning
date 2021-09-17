// 从左下角开始遍历
// 元素大于target则行数减一
// 元素小于target则列数加一

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        //从最后一行第一列开始搜索
        int row = m - 1;
        int col = 0;
        while (row >= 0 && col < n) {
            if (matrix[row][col] > target) {
                --row;
            } else if (matrix[row][col] < target) {
                ++col;
            } else {
                return true;
            }
        }
        return false;
    }
};