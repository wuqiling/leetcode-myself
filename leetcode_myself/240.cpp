#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix_3(matrix, target);
    }

   private:
    // brute force
    // time:O(M*N) space:O(1)
    // runtime: 964ms 1.4%
    bool searchMatrix_1(vector<vector<int>>& matrix, int target) {
        for (const auto& p : matrix)
            for (const auto& q : p)
                if (q == target) return true;
        return false;
    }

    // divide and conquer+ recursion
    // rumtime 1284ms 0.3%
    // https://articles.leetcode.com/searching-2d-sorted-matrix-part-ii/
    bool searchMatrix_2(const vector<vector<int>>& matrix, int target) {
        const int ROWS = matrix.size();
        if (ROWS == 0) return false;
        const int COLS = matrix[0].size();
        if (COLS == 0) return false;
        return quadPart(matrix, 0, ROWS - 1, 0, COLS - 1, target);
    }

    // recursion
    bool quadPart(const vector<vector<int>>& m, int rowStart, int rowEnd,
                  int colStart, int colEnd, int t) {
        if (rowStart > rowEnd || colStart > colEnd) return false;
        int rm = rowStart + (rowEnd - rowStart) / 2;
        int cm = colStart + (colEnd - colStart) / 2;
        if (m[rm][cm] == t)
            return true;
        else if (m[rm][cm] > t) {
            return quadPart(m, rowStart, rm - 1, colStart, cm - 1, t) ||
                   quadPart(m, rm, rowEnd, colStart, cm - 1, t) ||
                   quadPart(m, rowStart, rm - 1, cm, colEnd, t);
        } else {
            return quadPart(m, rm + 1, rowEnd, colStart, cm, t) ||
                   quadPart(m, rowStart, rm, cm + 1, colEnd, t) ||
                   quadPart(m, rm + 1, rowEnd, cm + 1, colEnd, t);
        }
    }

    // Smart algorithm;the upper-right element is the special one
    // time O(M+N) space O(1)
    // runtime 36ms 98%
    bool searchMatrix_3(const vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        if (ROWS == 0) return false;
        int COLS = matrix[0].size();
        if (COLS == 0) return false;
        int row = 0, col = COLS - 1;
        while (row < ROWS && col >= 0) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> m = {{1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 16, 22},
                             {10, 13, 14, 17, 24},
                             {18, 21, 23, 26, 30}};
    Solution s;
    bool ans = s.searchMatrix(m, 13);
    return 0;
}