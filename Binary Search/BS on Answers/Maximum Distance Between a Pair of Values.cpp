// Problem link ---->
https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/

// Solutions ---->

// Brute force (will get TLE)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int ans = 0;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = i; j < nums2.size(); j++) {

                if (nums1[i] <= nums2[j]) {
                    ans = max(ans, j - i);
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};

// Binary search
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int ans = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int low = i;
            int high = nums2.size() - 1;
            int mid;

            while (low <= high) {
                mid = low + (high - low) / 2;

                if (nums1[i] > nums2[mid]) {
                    high = mid - 1;
                } else {
                    ans = max(ans, mid - i);
                    low = mid + 1;
                }
            }

        }

        return ans;
    }
};

// Linear time, Beats 100%
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int i, j;

        for(i = 0, j = 0; i < nums1.size() && j < nums2.size(); j++) {
            if (nums1[i] > nums2[j]) {
                i++;
            }
        }

        return max(0, j - i - 1);
    }
};