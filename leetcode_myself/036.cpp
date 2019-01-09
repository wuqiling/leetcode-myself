#include <iostream>
#include <vector>

using std::vector;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValidSudoku_2(board);
    }

   private:
    // brute force + hash table
    // time O(1) space O(1)
    // runtime 12ms 97%
    bool isValidSudoku_1(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) return false;
        vector<vector<vector<char>>> table_box(
            3, vector<vector<char>>(3, vector<char>(256, 0)));
        vector<vector<char>> table_c(9, vector<char>(256, 0));
        vector<vector<char>> table_r(9, vector<char>(256, 0));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!table_c[i][board[i][j]])
                        table_c[i][board[i][j]] = 1;
                    else
                        return false;
                    if (!table_box[i / 3][j / 3][board[i][j]])
                        table_box[i / 3][j / 3][board[i][j]] = 1;
                    else
                        return false;
                }
                if (board[j][i] != '.') {
                    if (!table_r[i][board[j][i]])
                        table_r[i][board[j][i]] = 1;
                    else
                        return false;
                }
            }
        }
        return true;
    }

   private:
    // reduce space
    // runtime 4ms 100%
    bool isValidSudoku_2(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) return false;
        for (int i = 0; i < 9; i++) {
            vector<char> table_c(10, 0);
            vector<char> table_r(10, 0);
            vector<char> box(10, 0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!table_c[board[i][j] - '0'])
                        table_c[board[i][j] - '0'] = 1;
                    else
                        return false;
                }
                if (board[j][i] != '.') {
                    if (!table_r[board[j][i] - '0'])
                        table_r[board[j][i] - '0'] = 1;
                    else
                        return false;
                }
                int row = 3 * (i / 3) + j / 3;
                int col = 3 * (i % 3) + j % 3;
                if (board[row][col] != '.') {
                    if (!box[board[row][col] - '0'])
                        box[board[row][col] - '0'] = 1;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board{{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;
    bool ans = s.isValidSudoku(board);
    return 0;
}