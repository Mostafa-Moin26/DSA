// Problem link --->
https://leetcode.com/problems/missing-number/description/

// solution --->

// using formula
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        n = (n * (n + 1)) / 2;
        int sum = 0;

        for (auto i : nums) sum += i;

        return n - sum;

    }
};

// using bitwise operator
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i <= n; ++i) ans = ans ^ i;

        for (int i = 0; i < n; ++i) ans = ans ^ nums[i];

        return ans;

    }
};

// using sorting 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] != 0) return 0;

        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] - nums[i] > 1) {
                ans = nums[i] + 1;
                break;
            }
        }

        return ans == 0 ? n : ans;

    }
};

// using vector
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> v(n + 1, -1);

        for (int i = 0; i < n; ++i) v[nums[i]] = nums[i];

        for (int i = 0; i <= n; ++i) {
            if (v[i] == -1) return i;
        }
        return 0;

    }
};