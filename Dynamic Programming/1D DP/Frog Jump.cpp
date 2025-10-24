// Problem link ---->
https://www.naukri.com/code360/problems/frog-jump_3621012?leftPanelTabValue=PROBLEM&count=25&page=1&search=&sort_entity=order&sort_order=ASC

// Solutions ----->
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