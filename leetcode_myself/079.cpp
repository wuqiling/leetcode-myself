#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void printMatrix(vector<vector<int>> &m) {
    for (auto &i : m) {
        for (auto &j : i) cout << j << " ";
        cout << endl;
    }
    cout << endl;
}

class Solution {
   public:
    // dfs
    // worst time O(M*N*(4^L)) space O(L) L=len(word)
    // Runtime : 20 ms, faster than 80.20%
    bool exist(vector<vector<char>> &board, string word) {
        if (word.size() == 0) return true;
        if (board.size() == 0 || board[0].size() == 0) return false;
        _rows = board.size(), _cols = board[0].size();
        for (int row = 0; row < _rows; row++)
            for (int col = 0; col < _cols; col++)
                if (dfs(board, row, col, word, 0)) return true;

        return false;
    }

   private:
    bool dfs(vector<vector<char>> &board, int row, int col, const string &word,
             int idx) {
        if (col < 0 || col == _cols || row < 0 || row == _rows ||
            board[row][col] == '*' || board[row][col] != word[idx])
            return false;

        if (idx + 1 == word.size()) return true;
        char tmpChar = board[row][col];
        board[row][col] = '*';
        bool res = dfs(board, row, col - 1, word, idx + 1) ||
                   dfs(board, row, col + 1, word, idx + 1) ||
                   dfs(board, row - 1, col, word, idx + 1) ||
                   dfs(board, row + 1, col, word, idx + 1);
        board[row][col] = tmpChar;
        return res;
    }

   private:
    int _rows;
    int _cols;
};

int main() {
    string patten = "SEE";
    vector<vector<char>> board{
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

    Solution s;
    bool ans = s.exist(board, patten);
    return 0;
}