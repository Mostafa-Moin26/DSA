// Problem link --->
https://leetcode.com/problems/assign-cookies/description/


// Solution ---->
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int cnt = 0;

        for (int j = 0; j < s.size(); j++) {

            if (i < g.size() && g[i] <= s[j]) {
                cnt++;
                i++;
            }
        }

        return cnt;
    }
};

// little bit optimization
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int left = 0, right = 0;
        int cnt = 0;

        while (left < g.size() && right < s.size()) {
            if (g[left] <= s[right]) {
                cnt++;
                left++;
            }
            right++;
        }

        return cnt;
    }
};