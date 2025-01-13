// Problem Link ----->
https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

// Solutions ----->

// Brute force
// O(n^2) will get TLE
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        int ans = 0;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 1;
            int kk = k;
            for (int j = i + 1; j < nums.size(); j++) {
                kk -= (nums[i] - nums[j]);
                if (kk < 0) {
                    break;
                }
                cnt++;

            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};

// Optimal  (sorting + sliding window technique)
// O(logn + n)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        int n = nums.size();

        long long l, r, res, total;
        l = r = res = total = 0;
        sort(nums.begin(), nums.end());

        while (r < n) {
            total += nums[r];
            while (nums[r] * (r - l + 1) > total + k) {
                total -= nums[l];
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};