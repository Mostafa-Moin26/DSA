// Problem link ----> 
https://leetcode.com/problems/merge-sorted-array/description/

// Solution ---->
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int right = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[right] = nums1[i];
                i--;
            } else {
                nums1[right] = nums2[j];
                j--;
            }
            right--;
        }
    }
};