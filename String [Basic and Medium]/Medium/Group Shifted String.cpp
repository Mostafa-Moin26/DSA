// Problem link --->
https://www.geeksforgeeks.org/problems/group-shifted-string/1

// Solution --->

class Solution {
  public:
    vector<vector<string>> groupShiftedString(vector<string> &arr) {
        // Your code here
        
        unordered_map<string, vector<string>> mp;
        
        for (int i = 0; i < arr.size(); i++) {
            string s = arr[i];
            int dist = s[0] - 'a';
            
            for (int j = 0; j < s.size(); j++) {
                s[j] = (s[j] - dist - 'a' + 26) % 26 + 'a';
            }
            mp[s].push_back(arr[i]);
        }
        
        vector<vector<string>> ans;
        
        for (auto s : mp) {
            ans.push_back(s.second);
        }
        
        return ans;
        
    }
};