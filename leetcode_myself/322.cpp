#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        return coinChange_dfs_greedy_method2(coins, amount);
    }

   private:
    // time:O(size_array*amount) space:O(amount)
    // time:630ms 2%
    int coinChange_dp_method1(vector<int>& coins, int amount) {
        const int N = coins.size();
        if (amount == 0) return 0;
        if (N == 0 || amount < 0) return -1;

        // initialization
        unordered_map<int, long long> dp;
        dp[0] = 0;

        // state transfer
        long long sum;
        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < N; j++) {
                sum = (long long)i + coins[j];
                if (sum <= amount) {
                    if (dp.count(sum) == 0) dp[sum] = INT_MAX;
                    if (dp.count(i) == 0) dp[i] = INT_MAX;
                    dp[sum] = min(dp[i] + 1, dp[sum]);
                }
            }
            while (i <= amount && dp.count(i + 1) == 0) i++;
        }

        // return
        if (!dp.count(amount) || dp[amount] >= INT_MAX) return -1;
        return dp[amount];
    }

    // time:O(size_array*amount) space:O(amount)
    // time:8ms 98%
    // don't use map
    int coinChange_dp_method1_1(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        // time:8ms 98%
        for (int coin : coins)
            for (int i = coin; i <= amount; i++)
                dp[i] = min(dp[i], dp[i - coin] + 1);

        // time:24ms 55%
        // for(int i=0;i<=amount;i++){
        //     for(auto coin:coins){
        //         long long sum=(long long)coin+i;//might overflow
        //         if(sum<=amount)
        //             dp[sum]=min(dp[sum],dp[i]+1);
        //     }
        // }

        return dp[amount] >= amount + 1 ? -1 : dp[amount];
    }

    // dfs + greedy + pruning
    // time:4ms 99%
    int coinChange_dfs_greedy_method2(vector<int>& coins, int amount) {
        // sort in desending order
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        _dfs(coins, 0, amount, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }

    void _dfs(vector<int>& coins, int coin_idx, int amount, int count,
              int& ans) {
        const int coin = coins[coin_idx];  // current coin
        if (coin_idx == coins.size() - 1) {
            if (amount % coin == 0) ans = min(ans, count + amount / coin);
        } else {
            for (int i = amount / coin; i >= 0 && count + i < ans; i--)
                _dfs(coins, coin_idx + 1, amount - i * coin, count + i, ans);
        }
    }

   private:
    int min(long long a, long long b) { return a > b ? b : a; }
};

int main() {
    vector<int> coins = {2147483647};
    int amount = 2;
    Solution s;
    int res = s.coinChange(coins, amount);
    return 0;
}