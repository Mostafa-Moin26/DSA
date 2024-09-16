// Problem link ---->
https://leetcode.com/problems/subarray-sum-equals-k/description/

// Solution ---->
// brute force O(n^2) TLE
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); // taking the size of the array
        
        int ans = 0; // ans variable to store our count
        
        for(int i = 0; i < n; i++) // traverse from the array
        {
            int sum = arr[i]; // provide sum with arr[i]
            
            if(sum == k) // if element itself equal to k, then also increment count
                ans++;
            
            for(int j = i + 1; j < n; j++) // now moving forward,
            {
                sum += arr[j]; // add elements with sum
                
                if(sum == k) // if at any point they become equal to k
                    ans++; // increment answer
            }
            
        }
        
        return ans; // and at last, return answer
    }
};

// Optimal O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int > preSumMap;
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];
            if (sum == k) ans++;

            int rem = sum - k;

            if (preSumMap.find(rem) != preSumMap.end()) ans += preSumMap[rem];

             preSumMap[sum]++;
        }

        return ans;
    }
};