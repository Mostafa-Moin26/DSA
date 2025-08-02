// Problem link ---->
https://leetcode.com/problems/add-binary/description/

// solutions ----->

// Constructive algorithm made by myself
class Solution {
public:
    string addBinary(string a, string b) {
        
        if (b.size() > a.size()) {
            swap(a, b);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans = "";
        int carry = 0;
        for (int i = 0; i < a.size(); ++i) {

            if (i >= b.size()) {
                if (carry) {
                    if (a[i] == '1') ans.push_back('0');
                    else {
                        ans.push_back('1');
                        carry = 0;
                    }
                } else {
                    ans.push_back(a[i]);
                }
            } else {
                if (a[i] != b[i]) {
                    if (carry) ans.push_back('0');
                    else ans.push_back('1');
                } else {
                    if (a[i] == '0') {
                        if (carry) {
                            ans.push_back('1');
                            carry = 0;
                        }
                        else ans.push_back('0');
                    } else {
                        if (carry) ans.push_back('1');
                        else {
                            ans.push_back('0');
                            carry = 1;
                        }
                    }
                }
            }
        }
        if (carry) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

// Nice solution coppied from N7_BLACKHAT
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ans = "";
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {

            if (i >= 0) carry += a[i--] - '0';
            if (j >= 0) carry += b[j--] - '0';

            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Mix solution
class Solution {
public:
    string addBinary(string a, string b) {
        
        if (b.size() > a.size()) {
          return addBinary(b, a);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans = "";
        int carry = 0;

        for (int i = 0; i < a.size() || carry; i++) {

            if (i < a.size()) carry += a[i] - '0';
            if (i < b.size()) carry += b[i] - '0';

            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};