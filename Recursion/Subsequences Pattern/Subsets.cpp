// Problem link ---->
https://leetcode.com/problems/subsets/

// Solution ---->
class Solution {
public:
    void compute(int idx, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(current);
            return;
        }

        current.push_back(nums[idx]);
        compute(idx + 1, nums, current, ans);
        current.pop_back();
        compute(idx + 1, nums, current, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> current;

        compute(0, nums, current, ans);

        return ans;
    }
};

/*
Recursion tree for example [1, 2]

                         f(0, [])
                    take/        \not take
                       /          \
               f(1, [1])          f(1, [])
              /        \         /       \
             /          \       /         \
    f(2,[1,2])     f(2,[1])  f(2,[2])     f(2, [])


    sequence
    [1, 2]
    [1]
    [2]
    []
*/