#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
   public:
   //time O(N) space O(1)
   //runtime 24ms 98%
    int firstUniqChar(string s) {
        vector<int> table(256, 0);
        for (int i = 0; i < s.size(); i++) table[s[i]] += 1;

        for (int i = 0; i < s.size(); ++i)
            if (table[s[i]] == 1) return i;

        return -1;
    }
};

int main() {
    string str = "leetcode";
    Solution s;
    int ans = s.firstUniqChar(str);
    return 0;
}