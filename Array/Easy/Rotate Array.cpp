// Problem link ---->
https://leetcode.com/problems/rotate-array/description/

// solutions ---->
// brute force
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector<int> tmp = nums;

        int n = nums.size();
        k = k % n;

        int idx = 0;
        for (int i = n - k; i < n; ++i) {
            nums[idx++] = tmp[i]; 
        }

        for (int i = 0; i < n - k; ++i) {
            nums[idx++] = tmp[i];
        }


    }
};