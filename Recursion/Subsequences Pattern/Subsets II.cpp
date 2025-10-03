// Problem link ---->
https://leetcode.com/problems/subsets-ii/description/

// Solution ---->
class Solution {
public:
    
    void compute(int ind, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
        ans.push_back(current); 

        for (int i = ind; i < nums.size(); i++) {

            if (i > ind && nums[i] == nums[i - 1]) continue;

            current.push_back(nums[i]);
            compute(i + 1, nums, current, ans); 
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end()); 
        vector<int> current;
        vector<vector<int>> ans;

        compute(0, nums, current, ans);

        return ans;
    }
};