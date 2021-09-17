// dfs + 记忆化搜索
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        answer = vector<vector<int>> (m, vector<int>(n, 1));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }

private:
    // 子问题：从(x,y)出发能走多远
    // x：行号，y：列号
    int dfs(vector<vector<int>>& matrix, int x, int y) {
        // 算过了，直接返回（只算一次）
        if (answer[x][y] != 1)  return answer[x][y];
        // 四个方向
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)   continue;
            if (matrix[nx][ny] > matrix[x][y]) {
                answer[x][y] = max(answer[x][y], dfs(matrix, nx, ny) + 1);
            }
        }
        return answer[x][y];
    }
    int m, n;
    vector<vector<int>> answer;
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};
};

// bfs +　拓扑排序，没有dfs快
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        edges = vector<vector<int>> (m * n, vector<int>());
        deg = vector<int> (m * n, 0);
        dist = vector<int> (m * n, 0);        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (valid(ni, nj) && matrix[ni][nj] > matrix[i][j]) {
                        addEdge(calcNum(i, j), calcNum(ni, nj));
                    }
                }
            }
        }
        topSort();
        int ans = 0;
        for (int a : dist) {
            ans = max(ans, a);
        }
        return ans;
    }

private:
    void topSort() {
        queue<int> q;
        for (int i = 0; i < m * n; ++i) {
            if (deg[i] == 0)    q.push(i), dist[i] = 1;
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : edges[x]) {
                deg[y]--;
                dist[y] = max(dist[y], dist[x] + 1);
                if (deg[y] == 0) q.push(y);
            }
        }
    }
    int calcNum(int x, int y) {
        return x * n + y;
    }
    bool valid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    void addEdge(int u, int v) {
        edges[u].push_back(v);
        deg[v]++;
    }
    int m, n;
    vector<vector<int>> edges;
    vector<int> deg;
    vector<int> dist;
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};
};