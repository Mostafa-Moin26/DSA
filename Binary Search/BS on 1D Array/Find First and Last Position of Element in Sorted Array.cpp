// Problem link ---->
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = -1, end = -1;
        int low = 0, high = n - 1;

        // finding starting position
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                start = mid;
                high = mid - 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        low = 0, high = n - 1;

        // finding ending position
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                end = mid;
                low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {start, end};
    }
};

// Optimizing code
class Solution {
public:

    int binarySearch(vector<int> &nums, int target, bool isSearchingLeft) {
        int idx = -1;
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                idx = mid;
                if (isSearchingLeft) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = binarySearch(nums, target, true);
        int end = binarySearch(nums, target, false);
        return {start, end};
    }
};