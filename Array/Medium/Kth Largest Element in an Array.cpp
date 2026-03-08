// Problem link ---->
https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// Solutions --->

// using sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
    }
};

// using priority_queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};


// using cnt frequency
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        vector<int> cnt(20001, 0);

        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i] + 10000]++;
        }

        for (int i = 20000; i >= 0; i--) {

            k -= cnt[i];

            if (k <= 0) {
                return i - 10000;
            }
        }

        return -1;
    }
};