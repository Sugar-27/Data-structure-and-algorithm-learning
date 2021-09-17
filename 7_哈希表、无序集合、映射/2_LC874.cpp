class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // {(x1,y1), (x2,y2), ...}
        // (-200, 30000)
        // string: "-200,30000"
        // long long: (-200, 300) -->  (-200+30000, 300+30000) --> (-200+30000)*60000 + 300 + 30000
        unordered_set<long long> blockers;
        for (auto& obstacle : obstacles) {
            blockers.insert(calcHash(obstacle[0], obstacle[1]));
        }
    
        // 方向数组技巧
        //           N, E, S,  W
        int dx[4] = {0, 1, 0, -1}; // 偏移量（单位向量）
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0;
        int dir = 0; // N
        int ans = 0;
        for (int cmd : commands) {
            if (cmd > 0) {
                for (int i = 0; i < cmd; i++) {
                    // 尝试走到nextx, nexty
                    // 想向dir走一步，就加dir方向的偏移量
                    int nextx = x + dx[dir];
                    int nexty = y + dy[dir];
                    // 有障碍物
                    // calcHash(nextx, nexty) in blockers
                    if (blockers.find(calcHash(nextx, nexty)) != blockers.end()) {
                        break;
                    }
                    // 走一步
                    x = nextx;
                    y = nexty;
                    ans = max(ans, x * x + y * y);
                }
            } else if (cmd == -1) {
                // 0->1->2->3->0 
                // N->E->S->W->N
                // 右转（顺时针）
                dir = (dir + 1) % 4;
            } else {
                // 左转，避免负数，加一个mod数
                dir = (dir - 1 + 4) % 4;
            }
        }
        return ans;
    }

private:
    /*string calcHash(int x, int y) {
        return to_string(x) + "," + to_string(y);
    }*/
    long long calcHash(int x, int y) {
        return (x + 30000) * 60000ll + y + 30000; 
    }
};