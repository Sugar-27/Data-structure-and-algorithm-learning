class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        money[5] = money[10] = money[20] = 0;
        for (int& bill : bills) {
            money[bill]++;
            if (!exchange(bill)) {
                return false;
            }
        }
        return true;
    }

private:
    bool exchange(int bill) {
        bill -= 5; //收取费用五元
        while (bill >= 10 && money[10] > 0) {
            bill -= 10;
            money[10]--;
        }
        while (bill >= 5 && money[5] > 0) {
            bill -= 5;
            money[5]--;
        }
        return bill == 0;
    }

    unordered_map<int, int> money;
};