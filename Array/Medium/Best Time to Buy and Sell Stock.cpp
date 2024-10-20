// Problem Link ----->
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

// Solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {

       int buy = prices[0];
       int maxProfit = 0;

       for (int i = 1; i < prices.size(); i++) {

        if (prices[i] < buy) {
            buy = prices[i];
        }
        maxProfit = max(maxProfit, prices[i] - buy);
       } 

       return maxProfit;
    }
};