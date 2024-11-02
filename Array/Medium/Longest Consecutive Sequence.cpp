// Problem link ---->
https://leetcode.com/problems/longest-consecutive-sequence/description/

// Solutions ---->
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int lastSmallest = INT_MIN;
        int count = 0;
        int res = 1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] - 1 == lastSmallest) {
                count++;
                lastSmallest = nums[i];
            } else if (nums[i] != lastSmallest) {
                count = 1;
                lastSmallest = nums[i];
            }
            res = max(res, count);
        }

        return nums.size() > 0 ? res : 0;
    }
};

// using set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_set<int> st;
        int res = 1;

        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        for (auto i : st) {
            int count = 1;
            int x = i;
            if (st.find(x - 1) == st.end()) { // finding starting point
                while(st.find(x + 1) != st.end()) {
                    count++;
                    x++;
                }
            }
            res = max(res, count);
        }
        
        return res;
    }
};