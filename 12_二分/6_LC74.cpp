class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int top = -1, bot = m - 1;
        while (top < bot) {
            int mid = top + bot + 1 >> 1;
            if (matrix[mid][0] <= target) top = mid;
            else bot = mid - 1;
        }
        if (bot == -1) return false;
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (matrix[bot][mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (r == n || matrix[bot][r] != target) return false;
        return true;
    }
};