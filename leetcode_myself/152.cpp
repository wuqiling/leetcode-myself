#include <iostream>
#include <vector>

using std::vector;

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        if (N == 0) return 0;
        if (N == 1) return nums[0];

        // dp step 1  initialization
        int p, n, flagP, flagN;
        int res = nums[0];
        if (nums[0] > 0) {
            flagP = 1;
            flagN = 0;
            n = -1;
            p = nums[0];
        } else if (nums[0] < 0) {
            flagP = 0;
            flagN = 1;
            n = nums[0];
            p = 1;
        } else {
            flagP = 0;
            flagN = 0;
        }

        // dp step 2  function
        for (int i = 1; i < N; i++) {
            if (nums[i] > 0) {
                p = flagP ? p * nums[i] : nums[i];
                n = flagN ? n * nums[i] : -1;
                flagP = 1;
                res = p > res ? p : res;
            } else if (nums[i] < 0) {
                mySwap(p, n);
                mySwap(flagP, flagN);
                p = flagP ? p * nums[i] : 1;
                n = flagN ? n * nums[i] : nums[i];

				flagN = 1;
                res = nums[i] > res ? nums[i] : res;
				res = flagP&&p > res ? p : res;
            } else {
                flagP = flagN = 0;
                n = 1;
                p = -1;
                res = res < 0 ? 0 : res;
            }
        }

        // dp step 3
        return res;
    }

   private:
    void mySwap(int& a, int& b) {
        int t = a;
        a = b;
        b = t;
    }
};

int main() {
    Solution s;
    vector<int> a = {-4,-3};
    int ans = s.maxProduct(a);
    return 0;
}