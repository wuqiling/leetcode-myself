#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    int numDecodings(string s) {
        const int N = s.size();
        if (N == 0 || s[0] == '0') return 0;
        if (N == 1) return 1;

        int w1 = 1, w2 = 1;  // i-1 i-2
        for (int i = 1; i < N; i++) {
            int w = 0;
            if (!isValid(s[i]) && !isValid(s[i - 1], s[i])) return 0;
            if (isValid(s[i])) w = w1;
            if (isValid(s[i - 1], s[i])) w += w2;
            w2 = w1;
            w1 = w;
        }
        return w1;
    }

   private:
    bool isValid(const char c) { return c != '0'; }
    bool isValid(const char c1, const char c2) {
        return c1 == '1' || (c1 == '2' && c2 >= '0' && c2 <= '6');
    }
};

int main() {
    Solution s;
    s.numDecodings("1131");
    return 0;
}