// Problem link ------> 
https://leetcode.com/problems/reverse-pairs/description/

// Solutions ----->
// O(nlogn)
class Solution {
public:

    int countReversePairs(vector<int> &nums, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        int count = 0;

        while (left <= mid && right <= high) {
            if (nums[left] > 2LL * nums[right]) {
                count += (mid - left + 1);
                right++;
            } else {
                left++;
            }
        }

        return count;
    }
    int merge(vector<int> &nums, int low, int mid, int high) {
 
        vector<int> temp;
        int count = countReversePairs(nums, low, mid, high);

        int left = low;
        int right = mid + 1;
        for (int i = low; i <= high; i++) {
            if (left > mid) {
                temp.push_back(nums[right]);
                right++;
            } else if (right > high) {
                temp.push_back(nums[left]);
                left++;
            } else if (nums[left] > nums[right]) {
                temp.push_back(nums[right]);
                right++;
            } else {
                temp.push_back(nums[left]);
                left++;
            }
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[low + i] = temp[i];
        }

        return count;
    }
    int mergeSort(vector<int> &nums, int low, int high) {
        if (low >= high) return 0;

        int mid = (low + high) / 2;

        int val1 = mergeSort(nums, low, mid);
        int val2 = mergeSort(nums, mid + 1, high);
        int val3 = merge(nums, low, mid, high);

        return val1 + val2 + val3;
    }
    int reversePairs(vector<int>& nums) {
        

        int ans = mergeSort(nums, 0, nums.size() - 1);

        return ans;
    }
};