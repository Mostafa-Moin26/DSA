// Problem link --->
https://leetcode.com/problems/lemonade-change/description/

// Solution ---->
// my initial code
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        if (bills.size() == 1 && bills[0] != 5) {
            return false;
        }
        int five = 0, ten = 0;

        for (int i = 0; i < bills.size(); i++) {

            int change = bills[i] - 5;

            if (change == 15) {
                if (five == 0) {
                    return false;
                } else if (five < 3 && ten == 0) {
                    return false;
                } else {
                    if (ten != 0) {
                        ten--;
                        five--;
                    } else {
                        five -= 3;
                    }
                }
            }
            if (change == 5) {
                if (five == 0) {
                    return false;
                } else {
                    five--;
                }
            }

            if (bills[i] == 5) {
                five++;
            } else if (bills[i] == 10) {
                ten++;
            }
        }

        return true;
    }
};
// after optimization
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0, ten = 0;

        for (int i = 0; i < bills.size(); i++) {

            if (bills[i] == 5) {
                five++;
            } else if (bills[i] == 10) {
                if (five) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else {
                if (five && ten) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};