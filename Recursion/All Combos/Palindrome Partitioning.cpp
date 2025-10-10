// Problem link --->
https://leetcode.com/problems/palindrome-partitioning/description/


// Solution ---->
class Solution {
public:
    bool isPalindrome(string s, int start, int end) {

        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    void compute(string s, int index, vector<string>& path, vector<vector<string>>& ans) {

        if (index == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {

            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                compute(s, i + 1, path, ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<string> path;
        vector<vector<string>> ans;

        compute(s, 0, path, ans);

        return ans;
    }
};