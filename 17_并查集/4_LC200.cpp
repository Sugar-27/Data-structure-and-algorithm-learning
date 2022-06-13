// 并查集解法
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        fa.resize(m * n, 0);
        for (int i = 0; i < fa.size(); ++i) fa[i] = i;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') continue;
                for (int k = 0; k < 2; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                        continue;
                    } else if (grid[nx][ny] == '1') {
                        int set1 = find(i * n + j);
                        int set2 = find(nx * n + ny);
                        fa[set1] = set2;
                    }
                }
            }
        }
        unordered_set<int> st;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    st.insert(find(i * n + j));
                }
            }
        }
        return st.size();
    }
private:
    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    // 只需要往右走和往下走即可，之前的都遍历过
    const int dx[2] = {1, 0};
    const int dy[2] = {0, 1};
    int m, n;
    vector<int> fa;
};