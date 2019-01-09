#include <algorithm>
#include <vector>
using std::max;
using std::vector;

class Solution {
   public:
    // dfs + dp
    // time O(COLS*ROWS) space O(COLS*ROWS)
    // Runtime: 32 ms, faster than 67.98%
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) return 0;
        ROWS = matrix.size(), COLS = matrix[0].size();
        int res = 1;
        dp = vector<vector<int>>(ROWS, vector<int>(COLS, -1));
        for (int row = 0; row < ROWS; ++row) 
            for (int col = 0; col < COLS; ++col) 
                res = max(res, dfs(matrix, row, col));
            
        return res;
    }

   private:
    int COLS, ROWS;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int row, int col) {
        if (dp[row][col] != -1) return dp[row][col];
        int res = 1;
        if (row > 0 && matrix[row][col] < matrix[row - 1][col])
            res = max(res, 1 + dfs(matrix, row - 1, col));
        if (row + 1 < ROWS && matrix[row][col] < matrix[row + 1][col])
            res = max(res, 1 + dfs(matrix, row + 1, col));
        if (col > 0 && matrix[row][col] < matrix[row][col - 1])
            res = max(res, 1 + dfs(matrix, row, col - 1));
        if (col + 1 < COLS && matrix[row][col] < matrix[row][col + 1])
            res = max(res, 1 + dfs(matrix, row, col + 1));
        dp[row][col] = res;
        return res;
    }
};