class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        if (n >= 2 && islower(word[0]) && isupper(word[1]))    return false;
        else if (n <= 2)    return true;
        for (int i = 2; i < n; ++i) {
            if ((islower(word[i]) && islower(word[i - 1])) || (isupper(word[i]) && isupper(word[i - 1]))) continue;
            else {
                return false;
            }
        }
        return true;
    }
};