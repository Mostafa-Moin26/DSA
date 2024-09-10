// Problem Link ---->
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// Solutions ---->

// brute force 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        set<int> st;
        
        for (int i = 0; i < nums.size(); ++i) {
            st.insert(nums[i]);
        }

        int idx = 0;
        for (auto i : st) {
            nums[idx] = i;
            idx++;
        }

        return st.size();
    }
};

// better
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int c = 0;

        for (int i=1; i<nums.size(); ++i)
        {
            if (nums[i] == nums[i-1]) c++;

            else nums[i-c] = nums[i];
        }

        return nums.size()-c;
        
    }
};