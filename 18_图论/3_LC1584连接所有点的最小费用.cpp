// Kruskal算法
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> fa(n);
        for (int i = 0; i < n; ++i) fa[i] = i;
        vector<vector<int>> deal;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                deal.push_back({i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
            }
        }
        sort(deal.begin(), deal.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int ans = 0;
        for (int i = 0; i < deal.size(); ++i) {
            int x = deal[i][0], y = deal[i][1], d = deal[i][2];
            int fa1 = find(fa, x), fa2 = find(fa, y);
            if (fa1 == fa2) continue;
            else {
                fa[fa1] = fa2;
                ans += d;
            }
        }
        return ans;
    }
private:
    int find(vector<int>& fa, int x) {
        if (x == fa[x]) return fa[x];
        return fa[x] = find(fa, fa[x]);
    }
};