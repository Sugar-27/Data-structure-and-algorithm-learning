// 题目要求我们将打乱的英文单词重建为数字。
// 我们可以先对 s 进行词频统计，然后根据「英文单词中的字符唯一性」确定构建的顺序，最后再对答案进行排序即可。
// 具体的，zero 中的 z 在其余所有单词中都没出现过，我们可以先统计 zero 的出现次数，并构建 0；
// 然后观察剩余数字，其中 eight 中的 g 具有唯一性，构建 8；
// 再发现 six 中的 x 具有唯一性，构建 6；发现 three 中的 h 具有唯一性
//（利用在此之前 eight 已经被删除干净，词频中仅存在 three 对应的 h)，构建 33 ...
// 最终可以确定一个可行的构建序列为 0, 8, 6, 3, 2, 7, 5, 9, 4, 1

class Solution {
public:
    string originalDigits(string s) {
        for (char ch : s) {
            mpc[ch]++;
        }
        string ans;
        for (pair<string, int>& num : nums) {
            int k = INT_MAX;
            // 检测当前数字有几个，数字的个数等于其中字母最小的频数
            for (char ch : num.first) k = min(k, mpc[ch]);
            for (char ch : num.first) mpc[ch] -= k;
            // 添加数字
            while (k-- > 0)  ans.push_back('0' + num.second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
private:
    // 构建单词与数字的pair对，按顺序来检测
    vector<pair<string, int>> nums = {{"zero", 0}, {"eight", 8}, {"six", 6}, {"three", 3}, {"two", 2}, {"seven", 7},  {"five", 5}, {"nine", 9}, {"four", 4},{"one", 1}};
    // 记录无序字符串中所有字符出现的次数
    unordered_map<char, int> mpc;
};