// Problem Link ---->
https://leetcode.com/problems/reverse-integer/description/


// Solution ------>
// for only positive
class Solution {
public:
    int reverse(int x) {
        
        int ans = 0;

        while (x!=0)
        {
            int digit = x%10;

            if ((ans>INT_MAX/10) || (ans<INT_MIN/10))
            return 0;
            ans = ans * 10 + digit;
            x/=10;
        }
        return ans;
    }
};

// for positive and negative
class Solution {
public:
    int reverse(int x) {
        
        int res = 0;
        int temp = abs(x);

        while (temp > 0) {
            int rem = temp % 10;

            if ((res > INT_MAX / 10) || (res < INT_MIN / 10)) return 0;

            res = res * 10 + rem;
            temp = temp / 10;
        }

        return x < 0 ? -res : res;
    }
};