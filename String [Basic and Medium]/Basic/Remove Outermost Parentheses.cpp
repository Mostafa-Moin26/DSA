// Problem link ---->
https://leetcode.com/problems/remove-outermost-parentheses/

// Solutions ---->
// my solution
class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int cnt = 0;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                if (cnt) {
                    ans += '(';
                }
                cnt++;
            } else if (s[i] == ')') {
                cnt--;
                if (cnt) {
                    ans += ')';
                }
            }
        }

        return ans;
    }
};

// more shorter solution
class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int opened = 0;
        string ans = "";

        for (char ch : s) {

            if (ch == '(' && opened++ > 0) ans += ch;
            if (ch == ')' && opened-- > 1) ans += ch;
        }

        return ans;
    }
};