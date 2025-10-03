// Problem link ---->
https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1

// Solution ---->
class Solution {
public:
    vector<vector<int>> dp; 

    bool compute(int idx, int sum, vector<int>& nums, int k) {
        if (idx == nums.size()) {
            return sum == k;
        }

        if (dp[idx][sum] != -1) return dp[idx][sum];


        if (compute(idx + 1, sum, nums, k)) return dp[idx][sum] = 1;


        if (sum + nums[idx] <= k && compute(idx + 1, sum + nums[idx], nums, k))
            return dp[idx][sum] = 1;

        return dp[idx][sum] = 0;
    }

    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        dp.assign(n + 1, vector<int>(k + 1, -1));
        return compute(0, 0, arr, k);
    }
};
