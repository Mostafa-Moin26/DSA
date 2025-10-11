// Problem link ---->
https://leetcode.com/problems/word-break/

// Solution --->
// Without DP (TLE)
class Solution {
public:
    bool func(int indx, string s, vector<string>& wordDict) {
        if (indx == s.size()) {
            return true;
        }

        for (auto &word: wordDict) {
            int len = word.size();
            
            if (s.substr(indx, len) == word) {

                if (func(indx + len, s, wordDict)) return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        return func(0, s, wordDict);
    }
};

// Memoization
class Solution {
public:
    bool func(int indx, string s, vector<string>& wordDict, unordered_map<int, bool>& memo) {
        if (memo.count(indx)) return memo[indx];

        if (indx == s.size()) {
            return true;
        }

        for (auto &word: wordDict) {
            int len = word.size();
            
            if (s.substr(indx, len) == word) {

                if (func(indx + len, s, wordDict, memo)) return memo[indx] = true;
            }
        }
        return memo[indx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<int, bool> memo;
        return func(0, s, wordDict, memo);
    }
};