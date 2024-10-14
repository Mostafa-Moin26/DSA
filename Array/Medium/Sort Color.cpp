// Problem link ---->
https://leetcode.com/problems/sort-colors/description/

// Solutions
// My solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int zero = 0, one, two;
        one = two = nums.size() - 1;

        while (zero < one) {
            if (nums[zero] == 0) {
                zero++;
            } else if (nums[one] == 0) {
                swap(nums[zero], nums[one]);
                one--;
            } else {
                one--;
            }
        }

        if (nums[zero] == 0) zero++;

        one = zero;
        while (one < two) {
            if (nums[one] == 1) {
                one++;
            } else if (nums[two] == 1) {
                swap(nums[one], nums[two]);
                two--;
            } else {
                two--;
            }
        }


    }
};

// Dutch National Flag algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {

            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++, mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }

    }
};