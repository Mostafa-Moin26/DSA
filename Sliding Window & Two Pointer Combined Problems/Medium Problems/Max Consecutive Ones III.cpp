// Problem link ---->
https://leetcode.com/problems/max-consecutive-ones-iii/description/

// Solutions ---->
// My solution (also beats 100%)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int zeros = 0;
        int left = 0, right = 0;

        int ans = 0;

        while (right < nums.size()) {

            while (zeros <= k && right < nums.size()) {
                if (nums[right] == 0) {
                    zeros++;
                }
                right++;
            }
            ans = max(ans, right - left - 1);

            while (zeros > k && left < right) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
        }

        ans = max(ans, right - left);

        return ans;
    }
};

// After some optimization
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int zeros = 0;
        int left = 0, right = 0;

        int ans = 0;

        while (right < nums.size()) {

            if (nums[right] == 0) {
                zeros++;
            }

            while (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }

            if (zeros <= k) {
                ans = max(ans, right - left + 1);
            }
            right++;
        }

        return ans;
    }
};