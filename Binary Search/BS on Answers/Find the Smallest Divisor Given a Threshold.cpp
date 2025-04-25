// Problem link --->
https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

// Solution ---->
class Solution {
public:
    
    int sum(vector<int> &nums, int x) {

        int res = 0;

        for (int i = 0; i < nums.size(); i++) {

            res += (nums[i] - 1) / x + 1;
        }

        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {

            int mid = low + (high - low ) / 2;

            if (sum(nums, mid) > threshold) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};