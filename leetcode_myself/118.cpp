#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
   public:
    // time O(N^2) space O(N^2)
    // runtime ~0 100%
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            vector<int> tmp(i + 1, 1);
            for (int j = 1; i > 1 && j < i; j++)
                tmp[j] = res[i - 1][j - 1] + res[i - 1][j];
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> ans = s.generate(10);
    return 0;
}