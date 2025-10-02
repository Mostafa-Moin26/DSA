// Problem link ---->
https://leetcode.com/problems/combination-sum/description/

// Solution ----->
class Solution {
public:

    void compute(vector<int>& candidates, int i, int target, vector<int>& a, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(a);
            return;
        }
        if (i >= candidates.size() || target < 0) {
            return;
        }
        if (target >= candidates[i]) {
            a.push_back(candidates[i]);
            compute(candidates, i, target - candidates[i], a, ans);
            a.pop_back();
        }

        compute(candidates, i + 1, target, a, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> a;
        vector<vector<int>> ans;
        compute(candidates, 0, target, a, ans);
        return ans;
    }
};
