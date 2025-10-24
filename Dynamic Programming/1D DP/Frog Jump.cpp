// Problem link ---->
https://www.naukri.com/code360/problems/frog-jump_3621012?leftPanelTabValue=PROBLEM&count=25&page=1&search=&sort_entity=order&sort_order=ASC

// Solutions ----->

// Normal Recursion (will get TLE) 
#include <bits/stdc++.h> 

int compute(int ind, vector<int>& heights) {

    if (ind == 0) return 0;

    int first = compute(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int second = INT_MAX;
    if (ind > 1) second = compute(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);

    return min(first, second); 
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    return compute(n - 1, heights);
}

// Memoization
#include <bits/stdc++.h> 

int compute(int ind, vector<int>& heights, vector<int>& dp) {

    if (ind == 0) return 0;

    if (dp[ind] != -1) return dp[ind];

    int left = compute(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1) right = compute(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);

    dp[ind] = min(left, right);

    return dp[ind];
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n, -1);

    return compute(n - 1, heights, dp);
}

// Tabulation
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n, 0);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {

        int first = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int second = INT_MAX;
        if (i > 1) second = dp[i - 2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(first, second);
    }

    return dp[n - 1];
}

// Space Optimiztion
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    int prev = 0;
    int postPrev;
    int curr;

    for (int i = 1; i < n; i++) {

        int first = prev + abs(heights[i] - heights[i - 1]);
        int second = INT_MAX;
        if (i > 1) second = postPrev + abs(heights[i] - heights[i - 2]);

        curr = min(first, second);
        postPrev = prev;
        prev = curr;
    }

    return curr;
}