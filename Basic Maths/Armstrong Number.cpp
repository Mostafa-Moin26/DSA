//Problem Link ----->
https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1

// Solution ----->
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        int tmp = n;
        int res = 0;
        
        while (tmp > 0) {
            int lastDigit = tmp % 10;
            res += (lastDigit * lastDigit * lastDigit);
            tmp /= 10;
        }
        
        return res == n ? "true" : "false";
    }
};