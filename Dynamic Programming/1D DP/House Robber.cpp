// problem link --->
https://leetcode.com/problems/house-robber/description/

// Solutions ---->

// Normal recursion (will get TLE) 
class Solution {
public:

    int compute(vector<int>& nums, int ind) {
        if (ind == 0) return nums[ind];
        if (ind < 0) return 0;
        

        int rob = nums[ind] + compute(nums, ind - 2);
        int skip = compute(nums, ind - 1);

        return max(rob, skip);
    }
    int rob(vector<int>& nums) {

        return compute(nums, nums.size() - 1);

    }
};

// Memoization
class Solution {
public:

    int compute(vector<int>& nums, int ind, vector<int>& dp) {
        if (ind == 0) return nums[ind];
        if (ind < 0) return 0;
        
        if (dp[ind] != -1) return dp[ind];

        int rob = nums[ind] + compute(nums, ind - 2, dp);
        int skip = compute(nums, ind - 1, dp);

        return dp[ind] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);

        return compute(nums, nums.size() - 1, dp);

    }
};

// Tabulation
class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {

            int rob = nums[i] + dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = max(rob, skip);
        }

        return dp[n - 1];
    }
};


// Space optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev = max(nums[0], nums[1]);
        int postPrev = nums[0];

        for (int i = 2; i < n; i++) {
            int rob = nums[i] + postPrev;
            int skip = prev;
            int curr = max(rob, skip);

            postPrev = prev;
            prev = curr;
        }

        return prev;

    }
};