#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;


static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        m_ways[""] = 1;
        return ways(s);
    }

   private:
    // time:O(N^2) space:O(N^2)
    unordered_map<string, int> m_ways;
    int ways(const string &s) {
        if (m_ways.count(s)) return m_ways[s];
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        int w = ways(s.substr(1));  // sub str = s[1:end]
        if (stoi(s.substr(0, 2)) <= 26)
            w += ways(s.substr(2));  // sub str= s[0:1]

        m_ways[s] = w;
        return w;
    }
};

int main() {
    Solution s;
    s.numDecodings("1131");
    return 0;
}