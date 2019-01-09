#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
   public:
    // time ? space ?
    // Runtime: 0 ms, faster than 100.00%
    bool isHappy(int n) {
        unordered_set<int> hs;
        hs.insert(n);
        int64_t next = n;
        int64_t cur = 0;
        while (1) {
            cur = 0;
            while (next) {
                cur += (next % 10) * (next % 10);
                next /= 10;
            }
            if (cur == 1) return true;
            if (hs.count(cur)) return false;
            hs.insert(cur);
            next = cur;
        }
        return false;
    }
};

int main() {
    Solution s;
    bool ans = s.isHappy(19);
    return 0;
}