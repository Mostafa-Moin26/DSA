// Problem link --->
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// Solution ---->
class Solution {
public:
    bool isPossible(vector<int> &a, int capacity, int days) {
        int cnt = 1;
        int load = 0;

        for (int i = 0; i < a.size(); i++) {
            
            load += a[i];
            if (load > capacity) {
                load = a[i];
                cnt++;
            }
        }

        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(weights, mid, days)) {
              high = mid - 1;  
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};