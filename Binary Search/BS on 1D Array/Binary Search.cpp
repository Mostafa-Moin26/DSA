// Problem link ------>
https://leetcode.com/problems/binary-search/description/

// Solution ------>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int left = 0, right = n - 1;
        int mid;

        while (left <= right) {
            // mid = (left + right) / 2; not safe for large value
            mid = left + (right - left) / 2; // safe

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};