//Problem Link ----->
https://leetcode.com/problems/maximum-subarray/description/

// Solutions ------>

// Brute force O(N^2) TLE
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum;
        int maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

// Optimal solution using Kadane's Algorithm
// TC O(N) and O(1) space
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];
            maxSum = max(maxSum, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxSum;
    }
};