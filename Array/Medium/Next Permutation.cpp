// Problem link ---->
https://leetcode.com/problems/next-permutation/description/

// Solutions

// using STL
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

//Optimized solution
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int idx = -1;
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--) {

            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            sort(nums.begin(), nums.end());
        } else {
            for (int i = n - 1; i > idx; i--) {
                if (nums[i] > nums[idx]) {
                    swap(nums[i], nums[idx]);
                    break;
                }
            }
            sort(nums.begin() + idx + 1, nums.end());
        }
    }
};