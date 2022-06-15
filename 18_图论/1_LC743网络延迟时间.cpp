// Bellman-Ford算法
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n + 1, 1e9);
        dis[k] = 0;
        for (int i = 1; i < n; ++i) {
            bool change = false;
            for (vector<int>& time : times) {
                int x = time[0], y = time[1], d = time[2];
                if (dis[x] + d < dis[y]) {
                    change = true;
                    dis[y] = dis[x] + d;
                }
            }
            if (!change) break;
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dis[i]);
        }
        return ans < 1e9 ? ans : -1;
    }
};

// Dijkstra算法——本质上是一个用优先队列来做的BFS
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> edges(n + 1);
        for (auto& t : times) {
            int x = t[0], y = t[1], d = t[2];
            edges[x].push_back({y, d});
        }
        vector<int> dis(n + 1, 1e9);
        vector<bool> visit(n + 1, false);
        dis[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        q.push({dis[k], k});
        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (visit[x]) continue;
            visit[x] = true;
            for (auto& [y, d] : edges[x]) {
                if (dis[x] + d < dis[y]) {
                    dis[y] = dis[x] + d;
                    q.push({dis[y], y});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dis[i]);
        }
        return ans < 1e9 ? ans : -1;
    }
private:
    struct cmp {
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        }
    };
};