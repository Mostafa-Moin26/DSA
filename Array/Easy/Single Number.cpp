// Problem Link ----->
https://leetcode.com/problems/single-number/description/


// Solutions ----->

// brute force
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans;

        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;

            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    cnt++;
                }
            }
            if (cnt == 1) {
                ans = nums[i];
                break;
            }
        }

        return ans;
        
    }
};

// better
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        map<int, int> mp;
        int ans;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (auto i : mp) {
            if (i.second == 1) {
                ans = i.first;
                break;
            }
        }

        return ans;
        
    }
};

// using xor (optimal)
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) ans ^= nums[i];


        return ans;
        
    }
};