// 并查集解法
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        fa.resize(1001, 0);
        int n = edges.size();
        // 刚开始所有的点都认为是独立的点
        for (int i = 0; i < n; ++i) {
            fa[i] = i;
        }
        for (auto& edge : edges) {
            // 开始连接
            int set1 = find(edge[0]);
            int set2 = find(edge[1]);
            // 如果两个点连接之前就已经拥有相同的根，则说明出现了环路
            if (set1 == set2) return edge;
            // 连接两个点，把前一个节点的根设置为后一个节点
            fa[set1] = set2;
        }
        return {};
    }
private:
    int find(int x) {
        if (x == fa[x]) return fa[x];
        else return fa[x] = find(fa[x]);
    }
    vector<int> fa;
};

