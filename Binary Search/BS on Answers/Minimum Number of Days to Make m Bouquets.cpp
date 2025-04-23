// Problem link ---->
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

// Solution ---->
class Solution {
public:
    bool isPossible(vector<int> &a, int m, int k, int x) {

        int bouquets = 0;
        int cnt = 0;

        for (int i = 0; i < a.size(); i++) {

            if (a[i] <= x) {
                cnt++;
            } else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }
        bouquets += cnt / k;
        
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if ((long long)m * k > n) {
            return -1;
        }
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(bloomDay, m, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};