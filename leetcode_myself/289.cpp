#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    // time O(M*N) space O(1)
    // Runtime: 0 ms, faster than 100.00%
    void gameOfLife(vector<vector<int>> &board) {
        if (!board.size() == 0 || !board[0].size()) return;
        int rows = board.size(), cols = board[0].size();
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int c = 0;
                if (col - 1 >= 0) {
                    if (row - 1 >= 0 && board[row - 1][col - 1] & 1) c++;
                    if (board[row][col - 1] & 1) c++;
                    if (row + 1 < rows && board[row + 1][col - 1] & 1) c++;
                }
                if (row + 1 < rows && board[row + 1][col] & 1) c++;
                if (col + 1 < cols) {
                    if (row + 1 < rows && board[row + 1][col + 1] & 1) c++;
                    if (board[row][col + 1] & 1) c++;
                    if (row - 1 >= 0 && board[row - 1][col + 1] & 1) c++;
                }
                if (row - 1 >= 0 && board[row - 1][col] & 1) c++;

                if (c == 3 || (board[row][col] & 1 && c == 2))
                    board[row][col] |= 2;
            }
        }
        for (auto &row : board)
            for (auto &col : row) col >>= 1;
    }
};

int main() {
    vector<vector<int>> board{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};

    Solution s;
    s.gameOfLife(board);
    return 0;
}