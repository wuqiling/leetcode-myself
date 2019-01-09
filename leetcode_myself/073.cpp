#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;

void printM(const vector<vector<int>>& m) {
    for (auto& a : m) {
        for (auto& b : a) cout << b << "\t";
        cout << endl;
    }
    cout << endl;
}

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) { setZeroes_1(matrix); }

   private:
    // time O(M*N) space O(1)
    // runtime 48ms 44%
    void setZeroes_1(vector<vector<int>>& m) {
        const int rows = m.size();
        if (!rows) return;
        const int cols = m[0].size();
        if (!cols) return;
        int firstRow = 0, firstCol = 0;
        for (int i = 0; i < cols; i++)
            if (!m[0][i]) {
                firstRow = 1;
                break;
            }
        for (int i = 0; i < rows; i++)
            if (!m[i][0]) {
                firstCol = 1;
                break;
            }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (!m[i][j]) {
                    m[0][j] = 0;
                    m[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < rows; i++)
            for (int j = 1; j < cols; j++)
                if (!m[0][j] || !m[i][0]) m[i][j] = 0;
        if (firstRow)
            for (int i = 0; i < cols; i++) m[0][i] = 0;
        if (firstCol)
            for (int i = 0; i < rows; i++) m[i][0] = 0;
    }
};

int main() {
    vector<vector<int>> m{{1, 0, 1}};
    printM(m);
    Solution s;
    s.setZeroes(m);
    printM(m);
    return 0;
}