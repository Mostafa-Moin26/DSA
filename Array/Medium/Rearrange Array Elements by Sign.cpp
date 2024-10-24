// Problem Link ----->
https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

// Solution
//brute force
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> pos, neg;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                neg.push_back(nums[i]);
            } else {
                pos.push_back(nums[i]);
            }
        }

       for (int i = 0; i < pos.size(); i++) {
           nums[2 * i] = pos[i];
           nums[2 * i + 1] = neg[i];
       }

        return nums;
    }
};

//Optimal
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> res(nums.size());

        int pos = 0, neg = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                res[neg] = nums[i];
                neg += 2;
            } else {
                res[pos] = nums[i];
                pos += 2;
            }
        }

        return res;
    }
};