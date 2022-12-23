// 最简单的防止溢出方法1:用 long long
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

// 防止溢出的做法2，变乘为除
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x / 2 + 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return r;
    }
};