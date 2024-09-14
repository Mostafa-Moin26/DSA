// Problem Link ----->
https://leetcode.com/problems/two-sum/description/


// Solutions ----->

// brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

     for (int i=0; i<nums.size()-1; i++)
     for (int j=i+1; j<nums.size(); j++)
     if (nums[i]+nums[j]==target)
     return {i,j};

        return {};
    }
};

// using hash map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i=0; i<nums.size(); ++i)
        {
            int comp = target - nums[i];
            if (map.find(comp)!=map.end())
            return {map[comp], i};

            map[nums[i]] = i;
        }

        return {-1,-1};
    }
};