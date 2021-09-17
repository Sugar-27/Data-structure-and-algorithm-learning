class Solution {
public:
    double myPow(double x, long long n) {
        if (n < 0)  return 1 / myPow(x, -n);
        if (n == 0) return 1;
        double temp = myPow(x, n / 2);
        if (n % 2 == 1) return temp * temp * x;
        else return temp * temp;
    }
};