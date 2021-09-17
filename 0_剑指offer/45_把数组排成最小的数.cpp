// 数组转换成字符串，对字符串排序
// 重构sort函数的排序规则

class Solution {
public:
    string minNumber(vector<int>& nums) {
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), [] (string& a, string b) {
            return a + b < b + a;
        });
        string str;
        for (string s : strs) {
            str.append(s);
        }
        return str;
    }
private:
    vector<string> strs;
};