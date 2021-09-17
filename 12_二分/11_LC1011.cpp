//二分+贪心
class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = (left + right) / 2;
            if (canTrans(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

    bool canTrans(vector<int>& weights, int days, int mid) {
        int sum = 0;
        int countDay = 1;
        for (int& weight : weights) {
            if (weight > mid)
                return false;
            if (sum + weight <= mid) {
                sum += weight;
            } else {
                sum = weight;
                countDay++;
            }
        }
        return countDay <= days;
    }
};