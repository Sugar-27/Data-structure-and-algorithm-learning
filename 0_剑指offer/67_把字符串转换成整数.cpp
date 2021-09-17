class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        bool isNeg = false;
        bool hasNum = false;
        vector<int> nums;
        while (str[i] == ' ') ++i;
        if (str[i] == '-') {
            isNeg = true;
            i++;
        } else if(str[i] == '+') {
            i++;
        }
        while (str[i] == '0') ++i;
        //到达第一个非空字符
        while (str[i] >= '0' && str[i] <= '9') {
            hasNum = true;
            nums.push_back(str[i] - '0');
            i++;
        }
        if (!hasNum)    return 0;
        int res = 0;
        int bndry = 2147483647 / 10;
        for (int j = 0; j < nums.size(); ++j) {
            if (res > bndry || (res == bndry && nums[j] > 7))  return isNeg ? INT_MIN : INT_MAX;
            res = res * 10 + nums[j];
        }
        return isNeg ? -res : res;
    }
};