//Problem link --->
https://leetcode.com/problems/median-of-two-sorted-arrays/description/

// Solutions ---->
// Brute force
class Solution {
public:

    vector<int> merge(vector<int> &a, vector<int> &b) {
        vector<int> arr;
        int left = 0;
        int right = 0;

        while (left < a.size() && right < b.size()) {
            if (a[left] <= b[right]) {
                arr.push_back(a[left]);
                left++;
            } else {
                arr.push_back(b[right]);
                right++;
            }
        }

        while (left < a.size()) arr.push_back(a[left++]);
        while (right < b.size()) arr.push_back(b[right++]);

        return arr;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> a = merge(nums1, nums2);

        if (a.size() & 1) {
            return a[a.size() / 2];
        } else {
            int n = a.size();
            double res = (a[n / 2] + a[n / 2 - 1]) / 2.0;
            return res;
        }
        return -1;
    }
};

// Better, O(1) space
class Solution {
public:

    double merge(vector<int> &a, vector<int> &b) {
        int n1 = a.size();
        int n2 = b.size();
        int idx2 = (n1 + n2) / 2;
        int idx1 = idx2 - 1;
        int el1 = -1, el2 = -1;
        int i = 0, j = 0;
        int cnt = 0;

        while (i < n1 && j < n2) {

            if (a[i] <= b[j]) {
                if (cnt == idx1) el1 = a[i];
                if (cnt == idx2) el2 = a[i];

                i++, cnt++;
            } else {
                if (cnt == idx1) el1 = b[j];
                if (cnt == idx2) el2 = b[j];

                j++, cnt++;
            }
        }

        while (i < n1) {
            if (cnt == idx1) el1 = a[i];
            if (cnt == idx2) el2 = a[i];
            
            i++, cnt++;
        }
        while (j < n2) {
            if (cnt == idx1) el1 = b[j];
            if (cnt == idx2) el2 = b[j];

            j++, cnt++;
        }

        if ((n1 + n2) & 1) {
            return el2;
        }

        return (el1 + el2) / 2.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        return merge(nums1, nums2);
    }
};