// Problem Link ----->
https://leetcode.com/problems/move-zeroes/description/

// Solutions ----->
// brute force O(n) space
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nonZero;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) nonZero.push_back(nums[i]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i >= nonZero.size()) {
                nums[i] = 0;
            } else {
                nums[i] = nonZero[i];
            }
        }
        
    }
};

// Optimal solution using two pointer, O(1) space
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        if (nums.size() == 1) return;

        int n = nums.size();
        int i = 0;

        for (int j = 0; j < n; j++) {
            
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }


        }
        
    }
};