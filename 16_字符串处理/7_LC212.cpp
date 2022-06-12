// DFS + Trie
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        visit = vector<vector<bool>> (m, vector<bool> (n, false));
        root = new Node();
        // 字典树的插入，这里对字典树做了优化，只记录插入的字符串，不记录频次
        for (string& s : words) insert(s);
        // 常规搜索
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visit[i][j] = true;
                dfs(board, i, j, root);
                visit[i][j] = false;
            }
        }
        return ans;
    }
private:
    // Node里面存字符串和哈希表，哈希表用于找下一个Node
    // 当插入完成时将字符串设置为插入的字符串，用于标识到达搜索尾部，前缀部分的str则为空字符串
    struct Node {
        Node() : str("") {}
        string str;
        unordered_map<char, Node*> mp;
    };
    void insert(string& s) {
        Node* cur = root;
        for (char ch : s) {
            if (cur->mp.find(ch) == cur->mp.end()) {
                cur->mp[ch] = new Node();
            }
            cur = cur->mp[ch];
        }
        // 到达最后一个节点，节点的str设置为插入的字符串
        cur->str = s;
    }
    void dfs(vector<vector<char>>& board, int x, int y, Node* cur) {
        char ch = board[x][y];
        if (cur->mp.find(ch) == cur->mp.end()) return;
        // 父节点用来剪枝，如果子节点的哈希表是空的，父节点将这个子节点清除出去，减少搜索次数
        Node* fa = cur;
        cur = cur->mp[ch];
        if (cur->str.length() > 0) {
            ans.push_back(cur->str);
            cur->str = "";
        }
        if (cur->mp.empty()) {
            fa->mp.erase(ch);
            // 如果子节点是空的，则没有必要搜索了，不会往下走了
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || visit[nx][ny]) continue;
            visit[nx][ny] = true;
            dfs(board, nx, ny, cur);
            visit[nx][ny] = false;
        }
    }
    Node* root;
    vector<string> ans;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};
    int m, n;
    vector<vector<bool>> visit;
};