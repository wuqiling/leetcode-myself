#include <algorithm>
#include <iostream>
#include <vector>
using std::max;
using std::min;
using std::vector;

// Best Time to Buy and Sell Stock
class Solution {
   public:
    int maxProfit(vector<int>& prices) { return maxProfit_3(prices); }

   private:
    // brute force
    // time O(N^2) space O(1)
    // runtime 484ms 8%
    int maxProfit_1(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        if (prices.size() == 2)
            return prices[1] > prices[0] ? prices[1] - prices[0] : 0;
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (prices[j] < prices[i])
                    res = max(prices[i] - prices[j], res);
            }
        }
        return res;
    }

    // dp
    // time O(N) space O(N)
    // runtime ~0 100%
    int maxProfit_2(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        vector<int> dp(prices.size(), 0);
        int minVal = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i] = max(dp[i - 1], prices[i] - minVal);
            minVal = min(minVal, prices[i]);
        }
        return dp[prices.size() - 1];
    }

    // dp - 2
    // time O(N) space O(1)
    // runtime ~0 100%
    int maxProfit_3(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int maxVal = 0;
        for (int i = 1, minVal = prices[0]; i < prices.size(); i++) {
            maxVal = max(maxVal, prices[i] - minVal);
            minVal = min(minVal, prices[i]);
        }
        return maxVal;
    }
};

int main() {
    vector<int> prices{7, 1, 5, 3, 6, 4};

    Solution s;
    int ans = s.maxProfit(prices);
    return 0;
}