// Problem Link ---->
https://leetcode.com/problems/3sum/description/


// Solutions ---->

// Brute force 
// O(n^3) will get TLE

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int> > st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> tmp = {nums[i], nums[j], nums[k]};
                        sort(tmp.begin(), tmp.end());
                        st.insert(tmp);
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};

// Better
// O(n^2) In LeetCode, still get TLE
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int> > st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            set<int> hashSet;
            for (int j = i + 1; j < n; j++) {

                int third = -(nums[i] + nums[j]);

                if (hashSet.find(third) != hashSet.end()) {
                    vector<int> tmp = {nums[i], nums[j], third};
                    sort(tmp.begin(), tmp.end());
                    st.insert(tmp);
                }
                hashSet.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};

// Optimal
// O(1) space and near about O(n^2) time complexity
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    ans.push_back(tmp);
                    j++, k--;

                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};