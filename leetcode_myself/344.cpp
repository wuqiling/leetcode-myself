#include <string>

using std::string;

class Solution {
   public:
    // base string
    // time O(N) space O(N)
    // 4ms 100%
    string reverseString(string s) { return {s.rbegin(), s.rend()}; }
};

int main() {
    string str = "123";
    Solution s;
    string ans = s.reverseString(str);
    return 0;
}