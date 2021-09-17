// 利用分治思想进行递归求x的n次方
class Solution {
public:
    double myPow(double x, long long n) {
        if (n < 0) return 1 / myPow(x, -n);
        if (n == 0) return 1;
        double temp = myPow(x, n / 2);
        if (n % 2 == 0) 
            return temp * temp;
        else
            return temp * temp * x;
    }
};