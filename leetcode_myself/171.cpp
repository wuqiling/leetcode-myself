#include <string>

using std::string;

class Solution {
   public:
    // math
    // time O(N) sapce O(1)
    // Runtime: 4 ms, faster than 98.86%
    int titleToNumber(string s) {
        int res = 0, n = s.size(), powVal = 1;
        for (int i = 0; i < n; ++i) {
            res += powVal * (s[n - i - 1] - 'A' + 1);
            powVal *= 26;
        }
        return res;
    }
};

int main() {
    int ans = Solution{}.titleToNumber("AA");
    return 0;
}