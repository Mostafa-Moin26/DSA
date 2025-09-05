// Problem link ---->
https://leetcode.com/problems/string-to-integer-atoi/description/

// Solution ---->
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0, sign = 1;
        long res = 0;

        while (i < n && s[i] == ' ') i++;

        if (i == n) return 0;

        if (s[i] == '-') sign = -1, i++;
        else if (s[i] == '+') i++;

        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');

            if (sign * res > INT_MAX) return INT_MAX;
            if (sign * res < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * res);
    }
};

// Recursion
class Solution {
public:
    
    int helper(string s, int i, int sign, long res) {

        if (i >= s.size() || !isdigit(s[i])) {
            return (int)(sign * res);
        }

        res = res * 10  + (s[i] - '0');

        if (sign * res > INT_MAX) return INT_MAX;
        if (sign * res < INT_MIN) return INT_MIN;

        return helper(s, i + 1, sign, res);
    }
    int myAtoi(string s) {
        int n = s.size();
        int i = 0, sign = 1;
        long res = 0;

        while (i < n && s[i] == ' ') i++;

        if (i == n) return 0;

        if (s[i] == '-') sign = -1, i++;
        else if (s[i] == '+') i++;

        return helper(s, i, sign, res);
    }
};