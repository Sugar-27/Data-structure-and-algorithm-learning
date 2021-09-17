class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        // 点数：4^8 = 2^16 = 65536
        // 建立映射使得查找从vector的O(n)变成O(1)
        unordered_set<string> bankSet;
        for (string& s : bank) bankSet.insert(s);
        // 常数数组
        const char gene[4] = {'A', 'C', 'G', 'T'};
        unordered_map<string, int> depth;
        queue<string> q;
        q.push(start);
        depth[start] = 0;
        while (!q.empty()) {
            // 取队头
            // s = "AACCGGTT"
            // ns = "AACCGGTA" or "AACCGGTC", ... 24种
            string s = q.front();
            q.pop();
            // 24条出边：位置（8种）* 变化成的字符（3种）
            // s[i]变成gene[j]
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 4; j++) {
                    if (s[i] == gene[j]) continue;
                    string ns = s;
                    ns[i] = gene[j];
                    // 如果bank里没有ns，说明ns不合法（不在库中），跳过
                    if (bankSet.find(ns) == bankSet.end()) continue;
                    // 走从s到ns的边
                    // depth里面没有contains字符串ns
                    if (depth.find(ns) == depth.end()) {
                        depth[ns] = depth[s] + 1;
                        q.push(ns);
                        if (ns == end) {
                            return depth[ns];
                        }
                    }
                }
        }
        return -1;
    }
};