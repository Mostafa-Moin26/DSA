// Problem link ----->
https://leetcode.com/problems/maximum-product-subarray/description/

// Solutions ----->
// Brute force
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxRes = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
           int res = 1;
           for (int j = i; j < nums.size(); j++) {
            res *= nums[j];
            maxRes = max(maxRes, res);
           }
        }

        return maxRes;
        
    }
};

// Optimal
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int res = INT_MIN;
        int n = nums.size();

        int prefix = 1, suffix = 1;

        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            res = max(res, max(prefix, suffix));
        }

        return res;
        
    }
};