// Problem link ---->
https://leetcode.com/problems/climbing-stairs/description/

// Solutions ----->

// Normal Recursive solution (will get TLE)
class Solution {
public:
    int climbStairs(int n) {
        
        if (n <= 2) return n;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// Memoization
class Solution {
public:

    int compute(int n, vector<int>& dp) {

        if (n <= 2) return n;

        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = compute(n - 1, dp) + compute(n - 2, dp);

        return dp[n];
    }
    int climbStairs(int n) {

      vector<int> dp(n + 1, -1); 

      return compute(n, dp); 
    }
};

// Tabulation
class Solution {
public:
    long long int dp[47];
    int climbStairs(int n) {
        
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= 46; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// Space Optimization
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