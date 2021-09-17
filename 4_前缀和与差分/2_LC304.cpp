// 二维前缀和模板题

class NumMatrix {
   public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        sums = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sums[i][j] = getSum(i, j - 1) + getSum(i - 1, j) -
                             getSum(i - 1, j - 1) + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) - getSum(row2, col1 - 1) -
               getSum(row1 - 1, col2) + getSum(row1 - 1, col1 - 1);
    }

    int getSum(int i, int j) {
        if (i >= 0 && j >= 0)
            return sums[i][j];
        return 0;
    }

   private:
    vector<vector<int>> sums;
    int m, n;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */