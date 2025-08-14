// Leetcode Problem 121: Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description
// Category: Dynamic Programming on Stocks
// Difficulty: Easy

#include <vector>
#include <algorithm>  // for std::max
#include <limits.h>   // for INT_MAX
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // Initialize minimum price to maximum possible value
        int maxProfit = 0;        // Initialize maximum profit to zero      

        for (int price : prices) {
            // Update the minimum price if the current price is lower
            if (price < minPrice) {
                minPrice = price;
            }
            // Calculate profit if selling at the current price
            int profit = price - minPrice;
            // Update maximum profit if the current profit is higher
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;  // Return the maximum profit found
    }
};
// Approach: Single pass through the prices array
// T.C. -> O(n) where n is the number of prices
// S.C. -> O(1) (constant space)
// Note: The function finds the maximum profit by keeping track of the minimum price seen so far
// and calculating the profit at each price point. It updates the maximum profit accordingly.
// This approach ensures that we only traverse the list once, making it efficient for large datasets.
