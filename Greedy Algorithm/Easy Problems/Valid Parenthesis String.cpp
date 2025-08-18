// Problem link --->
https://leetcode.com/problems/valid-parenthesis-string/description/

// Solution ---->
// brute force (will get TLE)
class Solution {
public:

    bool func(string s, int idx, int cnt) {

        if (cnt < 0) {
            return false;
        }
        if (idx == s.size()) {
            return cnt == 0;
        }

        if (s[idx] == '(') {
            return func(s, idx + 1, cnt + 1);
        }
        if (s[idx] == ')') {
            return func(s, idx + 1, cnt - 1);
        }

        return func(s, idx + 1, cnt + 1) || func(s, idx + 1, cnt - 1) || func(s, idx + 1, cnt);
    }
    bool checkValidString(string s) {
        
        return func(s, 0, 0);
    }
};
// after optimization (using Memoization)
class Solution {
public:
    vector<vector<int>> dp;

    bool func(string &s, int idx, int cnt) {
        if (cnt < 0) return false; 
        if (idx == s.size()) return cnt == 0; 

        if (dp[idx][cnt] != -1) return dp[idx][cnt];

        bool ans = false;
        if (s[idx] == '(') {
            ans = func(s, idx + 1, cnt + 1);
        } else if (s[idx] == ')') {
            ans = func(s, idx + 1, cnt - 1);
        } else { 
            ans = func(s, idx + 1, cnt + 1)  
               || func(s, idx + 1, cnt - 1)  
               || func(s, idx + 1, cnt);     
        }
        return dp[idx][cnt] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        dp.assign(n + 1, vector<int>(n + 1, -1)); 
        return func(s, 0, 0);
    }
};

// Most optimal solution (using ranger)
class Solution {
public:

    bool checkValidString(string s) {
        int mn = 0, mx = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                mn++;
                mx++;
            } else if (s[i] == ')') {
                mn--;
                mx--;
            } else {
                mn--;
                mx++;
            }

            if (mn < 0) {
                mn = 0;
            }
            if (mx < 0) {
                return false;
            }
        }

        return mn == 0;
    }
};