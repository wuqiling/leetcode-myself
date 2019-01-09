#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::min;
using std::swap;
using std::vector;

void printArray(const vector<int>& nums) {
    for (const auto& n : nums) cout << n << " ";
    cout << "\t" << endl;
}

void printM(const vector<vector<int>>& m) {
    for (auto& a : m) {
        for (auto& b : a) cout << b << "\t";
        cout << endl;
    }
    cout << endl;
}

class Solution {
   public:
    // time O(M*N) space O(1)
    // runtime ~0 100%
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        int rowL = 0, rowH = matrix.size() - 1;
        int colL = 0, colH = matrix[0].size() - 1;
        vector<int> res;
        while (colL < colH && rowL < rowH) {
            for (int i = colL; i < colH; i++) res.push_back(matrix[rowL][i]);
            for (int i = rowL; i < rowH; i++) res.push_back(matrix[i][colH]);
            for (int i = colH; i > colL; i--) res.push_back(matrix[rowH][i]);
            for (int i = rowH; i > rowL; i--) res.push_back(matrix[i][colL]);
            ++colL, ++rowL;
            --colH, --rowH;
            // printArray(res);
        }
        if (colL == colH) {
            for (int i = rowL; i <= rowH; i++) res.push_back(matrix[i][colL]);
        } else if (rowL == rowH) {
            for (int i = colL; i <= colH; i++) res.push_back(matrix[rowL][i]);
        }
        // cout << "res:" << endl;
        // printArray(res);
        return res;
    }
};

int main() {
    vector<vector<int>> m;
    int r = 5, c = 5;
    for (int i = 0, cnt = 1; i < r; i++) {
        vector<int> tmp;
        for (int j = 0; j < c; j++) {
            tmp.push_back(cnt++);
        }
        m.push_back(tmp);
    }
    printM(m);

    Solution s;
    vector<int> ans = s.spiralOrder(m);

    return 0;
}