class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // HashMap可用于分组
        // 从排序以后的字符串（aet）到一个数组（["ate","eat","tea"]）的map
        unordered_map<string, vector<string>> group;
        for (string& str : strs) {
            string copy = str;
            // 字符串里面的字符排序
            // Java: toCharArray()
            sort(copy.begin(), copy.end());
            // 分组
            group[copy].push_back(str);
            // cout << "Added " << str << " into group " << copy << endl;
        }

        vector<vector<string>> ans;
        // Java .keySet()
        // Python for .. in ...
        for (auto pr : group) {
            // pr.first == key
            // pr.second == value
            ans.push_back(pr.second);
        }
        return ans;
    }

    // 字符串长度分别是n1, n2, n3,....，总和是n
    // n1 log n1 + n2 log n2 + ....
    // <= n1 log n + n2 log n + ....
    // = (n1 + n2 + ...) log n
    // = n log n
};

/*
["eat", "tea", "tan", "ate", "nat", "bat"]
["aet", "aet", "ant", "aet", "ant", "abt"]
*/