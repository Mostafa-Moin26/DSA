// Problem Link ----->
https://leetcode.com/problems/powx-n/description/

// Solutions ---->

class Solution {
public:
    
    double solve(double x, long long n, double ans) {

        if (n == 1) return ans * x;

        if (n & 1) {
           return solve(x, n - 1, ans * x);
        }

        return solve(x * x, n / 2, ans);

    }
    double myPow(double x, int n) {

       if (n == 0) return 1.0;
        long long num = static_cast<long long>(n);
        if (num < 0) num = -num;

       double ans = solve(x, num, 1.0); 

       return n < 0 ? 1.0 / ans : ans;
    }
};