// Problem link ----> 
https://leetcode.com/problems/plus-one/description/

// solution ----->
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        vector<int> ans = digits;

        while (i >= 0 && ans[i] == 9) {
            ans[i] = 0;
            i--;
        }

        if (i < 0) {
            ans.insert(ans.begin(), 1); 
        } else {
            ans[i] += 1;
        }

        return ans;
    }
};
