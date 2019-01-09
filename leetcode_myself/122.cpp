#include <iostream>
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

//Best Time to Buy and Sell Stock II    
class Solution {
   public:
	   //time O(N) space O(1)
	   // runtime 4ms 99%
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int sum = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i - 1]) sum += prices[i] - prices[i - 1];

        return sum;
    }
};