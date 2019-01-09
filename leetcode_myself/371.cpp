#include <vector>

using std::vector;

class Solution {
   public:
    int getSum(int a, int b) { return getSum_2(a, b); }

   private:
    // time = space = O(1)
    // Runtime: 0 ms, faster than 100.00%
    int getSum_1(int a, int b) {
        unsigned int res = 0;
        for (unsigned int i = 1, c = 0; i != 0; i <<= 1) {
            res |= (a ^ b ^ c) & i;
            c = (((a & b) | (a & c) | (b & c)) & i) << 1;
        }
        return res;
    }

    // time = space = O(1)
	// Runtime: 0 ms, faster than 100.00%
    int getSum_2(int a, int b) {
        return b == 0 ? a : getSum_2(a ^ b, (a & b) << 1);
    }
};

int main() {
    Solution s;
    int ans = s.getSum(-2, 100);
    return 0;
}