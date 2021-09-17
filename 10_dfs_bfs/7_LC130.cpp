class Solution {
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        visit = vector<vector<bool>> (m, vector<bool> (n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !visit[i][j]) {
                    vector<pair<int, int>> record;
                    bfs(board, i, j, record);
                    bool hasEdge = false;
                    for (pair<int, int> re : record) {
                        if (re.first == 0 || re.second == 0 || re.first == m - 1 || re.second == n - 1) {
                            hasEdge = true;
                            break;
                        }
                    }
                    if (!hasEdge) {
                        for (pair<int, int> re : record) {
                            board[re.first][re.second] = 'X';
                        }
                    }
                }
            }
        }
    }

private:
    void bfs(vector<vector<char>>& board, int sx, int sy, vector<pair<int, int>>& record) {
        queue<pair<int, int>> q;
        q.push(make_pair(sx, sy));
        record.push_back(make_pair(sx, sy));
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >=m || ny >= n)  continue;
                if (!visit[nx][ny] && board[nx][ny] == 'O') {
                    q.push(make_pair(nx, ny));
                    record.push_back(make_pair(nx, ny));
                    visit[nx][ny] = true;
                }
            }
        }
    }
    int m, n;
    vector<vector<bool>> visit;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
};