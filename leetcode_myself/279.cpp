#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

/**
 * time: O(N^2) space:O(N)
 */
class Solution {
   public:
    int numSquares(int n) { return numSquares_dp(n); }

   private:
    // 50ms 70%
    int numSquares_dp_bfs(int n) {
        vector<int> dp(n + 1, -1);
        // bfs+dp
        //??
        dp[0] = 0;
        queue<int> que;
        que.push(0);
        for (; que.empty() == false; que.pop()) {
            int cur = que.front();
            for (int i = 1; i * i + cur <= n; i++) {
                if (dp[i * i + cur] == -1) {
                    dp[i * i + cur] = dp[cur] + 1;
                    que.push(i * i + cur);
                }
            }
        }
        return dp[n];
    }

    // 60ms 50%
    int numSquares_dp(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i - j * j] + 1, dp[i]);

        return dp[n];
    }

    int min(int a, int b) { return a > b ? b : a; }
};

int main() {
    Solution s;
    int n = s.numSquares(13);
    return 0;
}