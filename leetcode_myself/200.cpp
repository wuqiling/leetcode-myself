#include <vector>

using std::vector;

class Solution {
   public:
    // time O(2*V*E) sapce O(1)
    // Runtime: 8 ms, faster than 99.00%
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int row = 0; row < grid.size(); ++row)
            for (int col = 0; col < grid[0].size(); ++col)
                if (dfs(grid, row, col)) res += 1;

        return res;
    }

   private:
    // dir 0 ^ > V <(1,2,3,4)
    int dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
            return 0;
        if (grid[row][col] != '1') return 0;
        grid[row][col] = '0';
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
        return 1;
    }
};

int main() {
    vector<vector<char>> grid{
        {1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1}};
    Solution s;
    int ans = s.numIslands(grid);
    return 0;
}