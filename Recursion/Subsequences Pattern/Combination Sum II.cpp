// Problem link ---->
https://leetcode.com/problems/combination-sum-ii/description/

// Solution ---->
class Solution {
public:
    void compute(vector<int>& candidates, int ind, int target, vector<int>& current, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {

            if (i > ind && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            current.push_back(candidates[i]);
            compute(candidates, i + 1, target - candidates[i], current, ans);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        vector<vector<int>> ans;

        compute(candidates, 0, target, current, ans);

        return ans;
    }
};
