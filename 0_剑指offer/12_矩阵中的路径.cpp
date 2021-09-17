class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;
        m = board.size();
        n = board[0].size();
        visit = vector<vector<bool>>(m, vector<bool>(n, false));
        hasWord = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                string str;
                if (board[i][j] == word[0]){
                    dfs(0, board, i, j, str);
                }  
                if (hasWord)
                    return true;
            }
        }
        return hasWord;
    }

private:
    void dfs(int len, vector<vector<char>>& board, int x, int y, string& str) {
        if (len >= word.length() || hasWord) return;
        visit[x][y] = true;
        str.push_back(board[x][y]);
        if (str == word)    hasWord = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (!visit[nx][ny] && board[nx][ny] == word[len + 1]) {
                dfs(len+ 1, board, nx, ny, str);
            }
        }
        str.pop_back();
        visit[x][y] = false;
    }

    int m, n;
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};
    bool hasWord;
    vector<vector<bool>> visit;
    string word;
};