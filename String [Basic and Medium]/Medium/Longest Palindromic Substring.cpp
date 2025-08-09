// Problem link ---->
https://leetcode.com/problems/longest-palindromic-substring/description/

// Solutions ---->
// Get TLE on last test case
class Solution {
public:
    bool isPalindrome(const string& str) {
        int left = 0;
        int right = str.length() - 1;
        
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            ++left;
            --right;
        }
        
        return true;
    }
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
        
        int max_len = 1;
        string max_str = s.substr(0, 1);
        
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i + max_len; j <= s.length(); ++j) {
                if (j - i > max_len && isPalindrome(s.substr(i, j - i))) {
                    max_len = j - i;
                    max_str = s.substr(i, j - i);
                }
            }
        }

        return max_str;
    }

};

// Optimal
class Solution {
public:
    int expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }    
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            int odd = expandAroundCenter(s, i, i);
            int even = expandAroundCenter(s, i, i + 1);
            int max_len = max(odd, even);

            if (max_len > end - start) {
                start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
            }
        }

        return s.substr(start, end - start + 1);        
    }

};

// little bit easy to understand
class Solution {
public:
    string expandAroundCenter(string s, int left, int right) {

        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {

        if (s.length() <= 1) {
            return s;
        }

        string ans = "";

        for (int i = 0;i < s.length(); i++) {

            string odd = expandAroundCenter(s, i, i);
            string even = expandAroundCenter(s, i, i + 1);

            if (odd.length() > ans.length()) {
                ans = odd;
            }
            if (even.length() > ans.length()) {
                ans = even;
            }
        }

        return ans;
    }
};