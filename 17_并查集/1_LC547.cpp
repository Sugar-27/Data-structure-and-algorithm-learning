// 并查集模版题
// 把不同的城市不断合并成到一个集合内
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // 并查集构建
        for (int i = 0; i < isConnected.size(); ++i) fa.push_back(i);
        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = i + 1; j < isConnected.size(); ++j) {
                if (isConnected[i][j] != 1) continue;
                // 并查集合并模版
                int x = find(i), y = find(j);
                if (x != y) fa[x] = y;
            }
        }
        int ans = 0;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (fa[i] == i) ++ans;
        }
        return ans;
    }
private:
    // 并查集查找模版
    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    vector<int> fa;
};