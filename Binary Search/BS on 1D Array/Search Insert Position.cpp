// Problem link ----->
https://leetcode.com/problems/search-insert-position/description/

// Solutions ----->
// Normal Linier search, not optimal
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int pos = 0;
        for (; pos < nums.size(); ++pos) {
            if (nums[pos] == target) return pos;
            if (nums[pos] > target) break;
        }
        return pos;
    }
};

// optimal
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};

// more optimal
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1, mid;
    int ans = n;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
    }
};