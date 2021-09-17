// https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/solution/mian-shi-ti-14-ii-jian-sheng-zi-iitan-xin-er-fen-f/
// 根据数学规则推到得到如下切分规则：
// 最优：3，把绳子尽可能切为多个长度为 3 的片段，留下的最后一段绳子的长度可能为0,1,2三种情况。
// 次优：2，若最后一段绳子长度为 2 ；则保留，不再拆为 1+1。
// 最差：1，若最后一段绳子长度为 1 ；则应把一份 3 + 1替换为 2 + 2，因为 2 * 2 > 3 * 1

class Solution {
public:
    int cuttingRope(int n) {
        // 绳子长度小于4的时候，按照切分规则应不剪长度最大，但因为题目规定必须切分，因此返回n - 1
        if(n < 4) return n - 1;
        // n = a * 3 + b
        int a = n / 3;
        int b = n % 3;
        // 最优解
        if(b == 0) return (int) (myPow(3, a) % mod);
        // 最差解
        else if(b == 1) return (int) (myPow(3, a - 1) * 4 % mod);
        // 次优解
        else return (int) (myPow(3, a) * 2 % mod);
    }
private:
    // 快速幂解法求余，返回base^num
    int mod = 1000000007;
    long myPow(long base, int num){
        long res = 1;
        while(num > 0){
            if((num & 1) == 1){
                res *= base;
                res %= mod;
            }
            base *= base;
            base %= mod;
            num >>= 1;
        }
        return res;
    }
};

//　循环取余
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int a = n / 3;
        int b = n % 3;
        if (b == 0) return pow(3, a) % 1000000007;
        else if (b == 1)    return pow(3, a - 1) * 4 % 1000000007;
        else return pow(3, a) * b % 1000000007;
    }
    
    long long pow(int x, int n) {
        long rem = 1 ;
        for (int i = 0; i < n; i++) {
            rem = (rem * x) % mod;   
        }
        return rem;
    }
private:
    int mod = 1000000007;
};
