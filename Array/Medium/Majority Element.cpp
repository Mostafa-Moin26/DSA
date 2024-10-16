// Problem link ----->
https://leetcode.com/problems/majority-element/description/


// solutions ----->


// brute force O(n^2)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int res;

        for (int i = 0; i < n; ++i) {
            res = 0;

            for (int j = i; j < n; ++j) {
                if (nums[i] == nums[j]) res++;
            }
            if (res > n / 2) {
                res = nums[i];
                break;
            }
        }

        return res;
    }
};

// better solution using Hashing O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            mp[nums[i]]++;
        }

        int res;

        for (auto i : mp) {
            if (i.second > n / 2) {
                res = i.first;
                break;
            }
        }

        return res;
    }
};


// Optimal solution O(1) space, Moore's Voting Algorithm
// Intuition : If an element appears more than n / 2 will not cancelled 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element;
        int count = 0;

        for (int i = 0; i < n; i++) {

            if (count == 0) {
                element = nums[i];
                count++;
            } else if (nums[i] == element) {
                count++;
            } else {
                count--;
            }
        }

       /* If question says, such value might not be exist then,
        we have to check the element by using extra loop
        count = 0;
        for (int i = 0; i < n; ++i) {
        	if (nums[i] == element) {
        		count++;
        	}
        }
        if (count <= n / 2) return -1; */


        return element;
    }
};