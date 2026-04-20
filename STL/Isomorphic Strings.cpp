// Problem link ---->
https://leetcode.com/problems/isomorphic-strings/description/

// Solution ---->
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        vector<int> ascii(256, 0);
        map<char, char> mp;

        for (int i = 0; i < s.size(); i++) {

            if (mp.find(s[i]) == mp.end()) {
                int idx = t[i];
                if (ascii[idx]) {
                    return false;
                }
                ascii[idx] = 1;
                mp[s[i]] = t[i];
            } else {
                if (mp[s[i]] != t[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};