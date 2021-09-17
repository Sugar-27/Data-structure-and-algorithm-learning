class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = numbers.size() - 1;
        for (int i = 0; i < numbers.size(); ++i) {
            while (i < j && numbers[i] + numbers[j] > target)   j--;
            if (i < j && numbers[i] + numbers[j] == target) return {i + 1, j + 1};
        }
        return {};
    }
};