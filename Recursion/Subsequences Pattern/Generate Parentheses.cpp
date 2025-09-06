// Problem link ---->
https://leetcode.com/problems/generate-parentheses/description/

// Solution ---->
class Solution {
public:

    void func(vector<string>& ans, int left, int right, string s, int n) {

        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (left < n) {
            func(ans, left + 1, right, s + "(", n);
        }
        if (right < left) {
            func(ans, left, right + 1, s + ")", n);
        }
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;

        func(ans, 0, 0, "", n);

        return ans;
    }
};