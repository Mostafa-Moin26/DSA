// Problem Link --->
https://leetcode.com/problems/majority-element-ii/description/


// Solutions ---->

// using Hashing
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;

        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto i : mp) {
            if (i.second > n / 3) {
                res.push_back(i.first);
            }
        }

        return res;
    }
};

// using Moore's Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1, el2, cnt1, cnt2;
        cnt1 = cnt2 = 0;
        el1 = el2 = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1, el1 = nums[i];
            } else if (cnt2 == 0 && nums[i] != el1) {
                cnt2 = 1, el2 = nums[i];
            } else if (nums[i] == el1) {
                cnt1++;
            } else if (nums[i] == el2) {
                cnt2++;
            } else {
                cnt1--, cnt2--;
            }
        }
        
        vector<int> res;
        int mini = nums.size() / 3;

        cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el1) cnt1++;
            if (nums[i] == el2) cnt2++;
        }

        if (cnt1 > mini) res.push_back(el1);
        if (cnt2 > mini) res.push_back(el2);

        return res;
    }
};