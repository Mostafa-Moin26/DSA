// Problem Link ----->
https://leetcode.com/problems/excel-sheet-column-number/description/

// solutions ----->
// 1st solution
class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int res = 0;

        for (char ch : columnTitle) {
            int df = ch - 'A' + 1;
            res = res * 26 + df;
        }

        return res;
    }
};

// second solution
class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int res = 0, cnt = 0;
        int i = columnTitle.size() - 1;
        for (; i >= 0; --i) {
            res = res + (columnTitle[i] - 'A' + 1) * pow(26, cnt);
            cnt++;
        }

        return res;
    }
};