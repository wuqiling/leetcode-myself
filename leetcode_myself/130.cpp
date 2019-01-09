#include <vector>

using std::vector;

class Solution {
   public:
    // Runtime: 12 ms, faster than 99.65%
    void solve(vector<vector<char>>& board) {
        if (!(rows = board.size()) || !(cols = board[0].size())) return;
        for (int row = 0; row < rows; ++row) {
            dfs(board, row, 0);
            dfs(board, row, cols - 1);
        }
        for (int col = 1; col < cols - 1; ++col) {
            dfs(board, 0, col);
            dfs(board, rows - 1, col);
        }
        for (auto& row : board)
            for (auto& col : row) col = (col == 'Z') ? 'O' : 'X';
    }

   private:
    int cols, rows;
    void dfs(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] != 'O') return;
        board[row][col] = 'Z';
        if (row > 0) dfs(board, row - 1, col);
        if (row + 1 < rows) dfs(board, row + 1, col);
        if (col > 0) dfs(board, row, col - 1);
        if (col + 1 < cols) dfs(board, row, col + 1);
    }
};

int main() {
     vector<vector<char>> board{
        {'O', 'X', 'X', 'O', 'X'}, {'X', 'O', 'O', 'X', 'O'},
        {'X', 'O', 'X', 'O', 'X'}, {'O', 'X', 'O', 'O', 'O'},
        {'X', 'X', 'O', 'X', 'O'},
    };

    Solution s;
    s.solve(board);
    return 0;
}