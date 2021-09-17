class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int left = 1, right = piles[piles.size() - 1];
        while (left < right) {
            int mid = (left + right) / 2;
            if (canEat(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

    bool canEat(vector<int>& piles, int mid, int h) {
        int sum = 0;
        for (int pile : piles) {
            sum += pile % mid == 0 ? pile / mid : pile / mid + 1;
        }
        return sum <= h;
    }
};