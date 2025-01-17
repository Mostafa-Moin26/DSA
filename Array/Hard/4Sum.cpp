// Problem link ----->
https://leetcode.com/problems/4sum/description/

// Solutions ---->

// first approach, O(n^3) will get TLE
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<int> hashSet;
                for (int k = j + 1; k < n; k++) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;

                    if (hashSet.find(fourth) != hashSet.end()) {
                        vector<int> tmp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(tmp.begin(), tmp.end());
                        st.insert(tmp);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> res(st.begin(), st.end());

        return res;
    }
};

// Optimal, it's near about O(n^3) and we do not use extra space to solve this problem, we are using ans matrix for store the result.
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<vector<int>> ans; 

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++, right--;

                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};