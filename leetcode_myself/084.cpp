#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using std::max;
using std::min;
using std::stack;
using std::vector;

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        return largestRectangleArea_2(heights);
    }

   private:
    // brute force
    // time O(N^2) space O(1)
    // Time Limit Exceeded
    int largestRectangleArea_1(vector<int>& heights) {
        const int n = heights.size();
        if (n == 1) return heights[0];
        int res = 0;
        for (int i = 0, lmin = 0; i < n; i++) {
            lmin = heights[i];
            res = max(res, heights[i]);
            if (heights[i] == 0) continue;
            for (int j = i + 1; j < n; j++) {
                lmin = min(lmin, heights[j]);
                res = max(res, lmin * (j - i + 1));
            }
        }
        return res;
    }

    // stack
    // time O(N) space O(N)
    // Runtime: 12 ms, faster than 44.73%
    int largestRectangleArea_2(vector<int>& heights) {
        stack<int> s;
        int res = 0;
        for (int i = 0; i <= heights.size(); i++) {
            int h = (i == heights.size()) ? 0 : heights[i];
            while (!s.empty() && h < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int start = s.empty() ? -1 : s.top();
                res = max(res, height * (i - start - 1));
            }
            s.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> heights{1, 2, 3};

    Solution s;
    int ans = s.largestRectangleArea(heights);
    return 0;
}