// Problem link ---->
https://leetcode.com/problems/binary-subarrays-with-sum/

// Solutions ---->
class Solution {
public:
    
    int func(vector<int>& nums, int goal) {

        if (goal < 0) return 0;

        int left = 0, right = 0, cnt = 0;
        int sum = 0;

        while (right < nums.size()) {

            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            cnt += (right - left + 1);
            right++;
        }

        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return func(nums, goal) - func(nums, goal - 1);
    }
};

// Beats 100%
class Solution {
public:
    
    int func(vector<int>& nums, int goal) {

        if (goal < 0) return 0;

        int left = 0, right, cnt = 0;
        int sum = 0;

        for (right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while (sum > goal && left <= right) {
                sum -= nums[left];
                left++;
            }
            cnt += (right - left + 1);
        }

        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return func(nums, goal) - func(nums, goal - 1);
    }
};