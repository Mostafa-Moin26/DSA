// Problem link ---->
https://leetcode.com/problems/permutations/description/

// Solution ---->
class Solution {
public:
    
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& ans) {

        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, ans);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans; 

        backtrack(nums, 0, ans);

        return ans;
        
    }
};