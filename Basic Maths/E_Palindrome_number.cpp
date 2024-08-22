// Problem link --->
https://leetcode.com/problems/palindrome-number/description/

// solution --->
class Solution {
public:
    bool isPalindrome(int x) {
        int tmp = x;
        long long int rev = 0;

        while (tmp > 0) {
            int lastDigit = tmp % 10;
            rev = rev * 10 + lastDigit;
            tmp = tmp / 10;
        }
        return rev == x;
    }
};