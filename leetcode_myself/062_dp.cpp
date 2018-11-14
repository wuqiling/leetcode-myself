#include <iostream>
#include <vector>

using std::vector;

class Solution {
   public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;

        // step 1:initialization
        vector<vector<int>> dp(m, vector<int>(n, 1));
        // for (int i = 0; i < n; i++) dp[0][i] = 1;
        // for (int i = 0; i < m; i++) dp[i][0] = 1;

        // step 2:Transfer equation
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        // step 3:goal
        return dp[m - 1][n - 1];
    }
};