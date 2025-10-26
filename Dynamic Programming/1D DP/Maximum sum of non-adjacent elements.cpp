// problem link --->
https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?interviewProblemRedirection=true&search=non&leftPanelTabValue=PROBLEM

// Solutions ---->

// Normal recursion (will get TLE) 
#include <bits/stdc++.h> 

int compute(vector<int>& nums, int ind) {

    if (ind == 0) {
        return nums[ind];
    }
    if (ind < 0) return 0;


    int pick = nums[ind] + compute(nums, ind - 2);
    int _not = compute(nums, ind - 1);

    return max(pick, _not);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    return compute(nums, nums.size() - 1);
}

// Memoization
#include <bits/stdc++.h> 

int compute(vector<int>& nums, int ind, vector<int>& dp) {

    if (ind == 0) {
        return nums[ind];
    }
    if (ind < 0) return 0;

    if (dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + compute(nums, ind - 2, dp);
    int _not = compute(nums, ind - 1, dp);

    return dp[ind] = max(pick, _not);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    vector<int> dp(nums.size(), -1);

    return compute(nums, nums.size() - 1, dp);
}
// Tabulation
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();

    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n + 1, 0);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {

        int pick = nums[i] + dp[i - 2];
        int _not = dp[i - 1];

        dp[i] = max(pick, _not);
    }

    return dp[n - 1];

}

// Space optimization
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];


    int postPrev = nums[0];
    int prev = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {

        int pick = nums[i] + postPrev;
        int _not = prev;

        int curr = max(pick, _not);
        postPrev = prev;
        prev = curr;
    }

    return prev;

}