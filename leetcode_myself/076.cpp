#include <iostream>
#include <string>
using std::string;

class Solution {
   public:
    // two pointer + greedy
    // time O(N) space O(1)
    // runtime 4ms 99%
    string minWindow(string s, string t) {
        int M = s.size(), N = t.size();
        if (!M || !N || M < N) return "";
        int tmap[256] = {0};
        int smap[256] = {0};
        for (int i = 0; i < N; ++i) ++tmap[t[i]];
        int minLen = INT_MAX, minStart = 0, cnt = 0;
        for (int slow = 0, fast = 0; fast < M; ++fast) {
            char ch = s[fast];
            if (tmap[ch] <= 0) continue;
            if (++smap[ch] <= tmap[ch]) cnt++;
            if (cnt >= N) {
                while (smap[s[slow]] <= 0 || smap[s[slow]] > tmap[s[slow]]) {
                    --smap[s[slow]];
                    ++slow;
                }
                if (fast - slow + 1 < minLen) {
                    minLen = fast - slow + 1;
                    minStart = slow;
                }
            }
        }
        if (minLen < INT_MAX)
            return s.substr(minStart, minLen);
        else
            return "";
    }
};

int main() {
    Solution s;
    string ans = s.minWindow("ADOBECODEBANC", "ABC");
    return 0;
}