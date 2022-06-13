// 新解法，用并查集解决
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        fa.resize(m * n + 1, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                fa[i * n + j] = i * n + j;
            }
        }
        fa[m * n] = m * n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X') continue;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                        fa[find(i * n + j)] = find(m * n);
                    } else if (board[nx][ny] == 'O'){
                        fa[find(nx * n + ny)] = find(i * n + j);
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && find(i * n + j) != find(m * n)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    int find(int x) {
        return fa[x] == x ? x : (fa[x] = find(fa[x]));
    }
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};
    int m, n;
    vector<int> fa;
};