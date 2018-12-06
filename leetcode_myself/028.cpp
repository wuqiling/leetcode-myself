#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        return strStr_2(haystack, needle);
    }

   private:
    // brute force
    // time O(N*M) space O(1)
    // runtime 4ms 98%
    int strStr_1(const string &haystack, const string &needle) {
        if (needle.size() == 0) return 0;
        for (int i = 0; i + needle.size() <= haystack.size(); ++i) {
            int flag = 1;
            for (int j = 0; j < needle.size(); ++j) {
                if (haystack[i + j] != needle[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) return i;
        }
        return -1;
    }

    // KMP
    // time O(N+M) space O(M)
    // runtime ~0 100%
    int strStr_2(const string &haystack, const string &needle) {
        int M = haystack.size(), N = needle.size();
        if (!N) return 0;
        vector<int> lps(N, 0);
        kmpProcess(needle, lps);

		//matching
        for (int i = 0, matchPos = 0; i < M;) {
            if (haystack[i] == needle[matchPos]) {
                if (matchPos == N - 1)
                    return i - matchPos;
                else
                    ++i, ++matchPos;
            } else {
                if (matchPos == 0)
                    ++i;
                else
                    matchPos = lps[matchPos - 1];
            }
        }
		return -1;
    }

    void kmpProcess(const string &str, vector<int> &lps) {
        for (int i = 1, len = 0; i < str.size();) {
            if (str[i] == str[len])
                lps.at(i++) = ++len;
            else if (len)
                len = lps.at(len - 1);
            else
                lps.at(i++) = 0;
        }
    }
};

int main() {
    Solution s;
    int ans = s.strStr("aaa", "aaa");
    return 0;
}