// Problem link ---->
https://leetcode.com/problems/find-the-duplicate-number/description/


// Solutions ---->
// using frequency array
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> freq(n,0);

        for (int i=0; i<n; ++i)
            freq[nums[i]]++;
        int ans;
        for (int i=1; i<n; ++i)
          if (freq[nums[i]]>1)
             ans = nums[i];
        return ans;
    }
};

// Optimal solutin using Floyed cycle detection algorithm
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

// Binary search 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};