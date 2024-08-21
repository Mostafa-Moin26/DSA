// Problem link ------>
https://leetcode.com/problems/valid-palindrome/description/

// Solutions ------>
// using recursion but memory limit exceeded at 480 no tes cases
class Solution {
public:
    
    string removeNonAlphanumericChar(string s) {

        string st;
        for (int i = 0; i < s.size(); ++i) {
            if ((tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z') || s[i] >= '0' && s[i] <= '9') {
                st.push_back(tolower(s[i]));
            }
        }

        return st;
    }

    bool checkPalindrome(int i, string s, int n) {
        if (i >= n / 2) return true;

        if (s[i] != s[n - i - 1]) return false;

        return checkPalindrome(i + 1, s, n);
    }
    bool isPalindrome(string s) {
        
        string st = removeNonAlphanumericChar(s);

        return checkPalindrome(0, st, st.size());
    }
};


// not using recursion 
class Solution {
public:
    
    string removeNonAlphanumericChar(string s) {

        string st;
        for (int i = 0; i < s.size(); ++i) {
            if ((tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z') || s[i] >= '0' && s[i] <= '9') {
                st.push_back(tolower(s[i]));
            }
        }

        return st;
    }

    bool checkPalindrome(string s) {

        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - i - 1]) return false;
        }

        return true;
    }
    bool isPalindrome(string s) {
        
        string st = removeNonAlphanumericChar(s);

        return checkPalindrome(st);
    }
};

// Optimal code
class Solution {
public:
    
    bool isPalindrome(string s) {
        
        int start = 0;
        int end = s.size() - 1;

        while (start <= end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }

            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            } else {
                start++, end--;
            }
        }

        return true;
    }
};