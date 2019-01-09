#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;

class Solution {
   public:
    int trap(vector<int>& height) { trap_1(height); }

   private:
    // time O(N) space O(N)
    // Runtime: 8 ms  72%
    int trap_1(vector<int>& height) {
        const int n = height.size();
        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);
        for (int i = 0, lmaxVal = 0, rmaxVal = 0; i < n; i++) {
            lmax[i] = lmaxVal;
            lmaxVal = max(lmaxVal, height[i]);
            rmax[n - 1 - i] = rmaxVal;
            rmaxVal = max(rmaxVal, height[n - 1 - i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int cur = min(lmax[i], rmax[i]) - height[i];
            if (cur > 0) res += cur;
        }
        return res;
    }

    // time O(N) space O(1)
    // Runtime: 8 ms, faster than 72.34%
    int trap_2(vector<int>& height) {
        const int n = height.size();
        int res = 0;
        for (int lmax = 0, rmax = 0, l = 0, r = n - 1; l < r;) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if (lmax < rmax)
                res += lmax - height[l++];
            else
                res += rmax - height[r--];
        }
        return res;
    }
};

int main() {
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution s;
    int ans = s.trap(height);
    return 0;
}