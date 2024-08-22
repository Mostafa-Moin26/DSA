// Problem link ----->

https://leetcode.com/problems/climbing-stairs/description/

// solutions ------>
// using Tabulation
class Solution {
public:
    int dp[47];
    int climbStairs(int n) {
        
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// space optimization
class Solution {
public:
    
    int climbStairs(int n) {
        
        if (n <= 2) return n;

        int first = 1, second = 2;
        int ans;
        for (int i = 3; i <= n; ++i) {
            ans = first + second;
            first = second;
            second = ans;
        }
        
        return ans;
    }
};
