#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
   public:
    int romanToInt(string s) { return romanToInt_1(s); }

   private:
    // time O(N) space O(1)
    // runtime 20ms 100%
    int romanToInt_1(string s) {
        int N = s.size();
        if (N == 0) return 0;
        int res = charToInt(s[0]);
        int cur = 0, pre = charToInt(s[0]);
        for (int i = 1; i < N; i++) {
            cur = charToInt(s[i]);
            if (cur > pre)
                res += cur - 2 * pre;
            else
                res += cur;
            pre = cur;
        }
        return res;
    }

   private:
    int charToInt(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    // hash map
    // O(N)~O(N*M)=>hashmap: avg O(1) ~ worst O(M)
    // runtime 40ms 96%
    int romanToInt_2(string s) {
        int N = s.size();
        if (N == 0) return 0;
        const unordered_map<char, int> sti{
            {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000},
        };

        int res = sti.at(s[0]);
        int cur = 0, pre = sti.at(s[0]);
        for (int i = 1; i < N; ++i) {
            cur = sti.at(s[i]);
            if (cur > pre)
                res += cur - 2 * pre;
            else
                res += cur;
            pre = cur;
        }
        return res;
    }
};