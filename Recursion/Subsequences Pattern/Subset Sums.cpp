// Problem link ---->
https://www.geeksforgeeks.org/problems/subset-sums2234/1

// Solution ---->
class Solution {
  public:
    
    void compute(int ind, int sum, vector<int>& arr, vector<int>& ans) {
        
        if (ind == arr.size()) {
            ans.push_back(sum);
            return;
        }
        
        compute(ind + 1, sum + arr[ind], arr, ans);
        compute(ind + 1, sum, arr, ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        
        compute(0, 0, arr, ans);
        
        return ans;
    }
};