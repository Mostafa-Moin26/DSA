// Problem link ---->
https://leetcode.com/problems/split-array-largest-sum/description/

// Solution ---->
class Solution {
public:

    int func(vector<int> &nums, int x) {
        int subArrays = 1, sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (sum + nums[i] <= x) {
                sum += nums[i];
            } else {
                subArrays++;
                sum = nums[i];
            }
        }

        return subArrays;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (func(nums, mid) <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};