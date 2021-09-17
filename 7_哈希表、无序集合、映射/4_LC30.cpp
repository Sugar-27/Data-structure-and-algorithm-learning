//基础做法

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        wordsMap = countWrds(words);
        int tot = words.size() * words[0].size();
        vector<int> ans;
        // 枚举开始位置
        for (int start = 0; start + tot <= s.length(); start++) {
            if (isSame(s.substr(start, tot), words)) {
                ans.push_back(start);
            }
        }
        return ans;
    }

private:
    unordered_map<string, int> wordsMap;

    // 想判断一个字符串t，是否由words拼成
    // 把t分解成若干个单词，然后看跟words数组是否相同（顺序无关）
    bool isSame(string t, vector<string>& words) {
        // cout << "isSame: " << t << " and words" << endl;
        int m = words[0].length(); // 每个单词的长度
        unordered_map<string, int> tMap; // 单词出现次数
        // 把t，每m个字符分解成一个单词
        // foothe 分解为 foo, the
        for (int i = 0; i < t.length(); i += m) {
            // i开始的m个字符，组成一个单词
            tMap[t.substr(i, m)]++;
        }
        return equals(tMap, wordsMap);
    }

    // 判断两个map是否一样的方法
    // a.size() == b.size()
    // size: key的个数
    // a里面有的b里全有，且值一样
    bool equals(unordered_map<string, int>& a, unordered_map<string, int>& b) {
        if (a.size() != b.size()) return false;
        for (auto& key_value_pair : a) {
            auto& key = key_value_pair.first;
            auto& value = key_value_pair.second;
            // 如果b里面没有，或者value不相等（次数不一样）
            if (b.find(key) == b.end() || value != b[key]) return false;
        }
        return true;
    }

    unordered_map<string, int> countWords(vector<string>& words) {
        unordered_map<string, int> ans;
        for (string& word : words) {
            ans[word]++;
        }
        return ans;
    }
};

//bar foo
//arf oot
//rfo oth
//...

//优化做法
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int m = words[0].length();
        int n = s.length();
        for (string& word : words) {
            wordsMap[word]++;
        }
        int tot = words.size() * words[0].length();
        for (int first = 0; first < m; ++first) {
            if (first + tot > s.size()) break;
            int curr = first;
            unordered_map<string, int> sMap;
            for (int i = 0; i < words.size(); ++i) {
                sMap[s.substr(curr, m)]++;
                curr += m;
            }
            for (int start = first, end = curr; start + tot <= s.length(); start += m, end += m) {
                if (isSame(sMap, wordsMap))   ans.push_back(start);
                sMap[s.substr(end, m)]++;
                sMap[s.substr(start, m)]--;
            }
        }
        return ans;
    }

private:
    unordered_map<string, int> wordsMap;

    bool isSame(unordered_map<string, int>& a, unordered_map<string, int>& b) {
        for (auto& pr : a) {
            if (b[pr.first] != pr.second) return false;
        }
        for (auto& pr : b) {
            if (a[pr.first] != pr.second) return false;
        }
        return true;
    }
};