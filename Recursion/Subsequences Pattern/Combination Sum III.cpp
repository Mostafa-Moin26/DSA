// Problem link --->
https://leetcode.com/problems/combination-sum-iii/description/


// Solution ---->
class Solution {
public:

    void compute(vector<int>& current, vector<vector<int>>& ans, int k, int start, int target) {

        if (target == 0 && k == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i <= 9; i++) {

            if (i > target || k <= 0) break;

            current.push_back(i);

            compute(current, ans, k - 1, i + 1, target - i);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> current;
        vector<vector<int>> ans;

        compute(current, ans, k, 1, n);

        return ans;
    }
};