#include <iostream>

class Solution {
   public:
    // Runtime: 4 ms, faster than 88.03%
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i)
            if (n & (0x1 << i)) res |= 0x1 << (31 - i);
        return res;
    }
};

int main() {
    uint32_t ans = Solution{}.reverseBits(1);
    return 0;
}