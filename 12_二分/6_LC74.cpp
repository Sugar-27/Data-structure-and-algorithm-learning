class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size();
        n = matrix[0].size();
        int left = 0, right = m - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (matrix[mid][0] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        int row = right;
        left = -1, right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (matrix[row][mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        if (right == -1)
            return false;
        return matrix[row][right] == target ? true : false;
    }

   private:
    int m, n;
};