class Solution {
public:
    int movingCount(int m, int n, int k) {
        this->m = m;
        this->n = n;
        this->k = k;
        visit = vector<vector<bool>> (m, vector<bool> (n, false));
        ans = 0;
        dfs(0, 0);
        return ans;
    }

private:
    void dfs(int x, int y) {
        visit[x][y] = true;
        ans++;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (!visit[nx][ny] && check(nx, ny)) {
                dfs(nx, ny);
            }
        }
    }

    bool check(int x, int y) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        while (y) {
            sum += y % 10;
            y /= 10;
        }
        return sum <= k;
    }

    int ans;
    vector<vector<bool>> visit;
    int m, n, k;
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};
};