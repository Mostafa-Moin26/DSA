// Problem link --->
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

// My Solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        if (nums[0] < nums[n - 1]) {
            return nums[0];
        }

        int low = 0, high = n - 1;
        int minEl = 5001;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            minEl = min(minEl, nums[mid]);

            if (nums[low] > nums[mid]) {
                high = mid - 1;
            } else if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                break;
            }
        }

        return min(nums[low], minEl);
    }
};

// Optimal
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int minEl = INT_MAX;
        int low = 0, high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid]) {
                minEl = min(minEl, nums[low]);
                low = mid + 1;
            } else {
                minEl = min(minEl, nums[mid]);
                high = mid - 1;
            }
        }

        return minEl;
    }
};