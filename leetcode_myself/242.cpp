#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
   public:
    // time O(N) space O(1) <= char in range(0,256)
    // Runtime: 16 ms, faster than 36.24%
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> hm;
        for (char ch : s) ++hm[ch];
        for (char ch : t)
            if (!hm.count(ch) || hm[ch] == 0)
                return false;
            else
                --hm[ch];
        return true;
    }
};