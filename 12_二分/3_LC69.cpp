class Solution {
   public:
    int mySqrt(int x) {
        //找最大的ans，满足ans^2 <= x
        long long left = 0, right = x;
        while (left < right) {
            long long mid = (left + right + 1) / 2;
            if (mid * mid <= x) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};