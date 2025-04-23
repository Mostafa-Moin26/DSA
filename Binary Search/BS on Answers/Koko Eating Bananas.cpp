// Problem link ---->
https://leetcode.com/problems/koko-eating-bananas/description/

// Solution --->
class Solution {
public:
    
    bool isPossible(vector<int> &piles, int k, int h) {
        int cnt = 0;

        for (int i = 0; i < piles.size(); i++) {

            cnt += (piles[i] - 1) / k + 1;

            if (cnt > h) {
                return false;
            }
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(piles, mid, h)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};