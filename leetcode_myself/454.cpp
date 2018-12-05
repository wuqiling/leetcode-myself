#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

class Solution {
   public:
    // hashmap
    // time O(N^2) space O(N^2)
    // runtime 100 ms 94.50%
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                     vector<int>& D) {
        int N = A.size();
        if (N == 0) return 0;

        unordered_map<int, int> abSum;
        for (const auto& a : A)
            for (const auto& b : B) abSum[a + b]++;

        int res = 0;
        for (const auto& c : C)
            for (const auto& d : D) {
                int cdSum = -(c + d);
                if (abSum.count(cdSum) > 0) res += abSum[cdSum];
            }

        return res;
    }
};