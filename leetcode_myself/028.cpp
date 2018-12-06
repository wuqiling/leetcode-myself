#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        return strStr_2(haystack, patten);
    }

   private:
    // brute force
    // time O(N*M) space O(1)
    // runtime 4ms 98%
    int strStr_1(const string &str, const string &patten) {
        if (patten.size() == 0) return 0;
        for (int i = 0; i + patten.size() <= str.size(); ++i) {
            int flag = 1;
            for (int j = 0; j < patten.size(); ++j) {
                if (str[i + j] != patten[j]) {
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
    int strStr_2(const string &str, const string &patten) {
        int M = str.size(), N = patten.size();
        if (!N) return 0;
        vector<int> lps(N, 0);
        kmpProcess(patten, lps);

        // matching
        for (int i = 0, matchPos = 0; i < M;) {
            if (str[i] == patten[matchPos]) {
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

    // BM
    // time O(N)~worst O(M*N) space O(1)
    // runtime ~0 100%
    int strStr_3(const string &str, const string &patten) {
        int M = str.size(), N = patten.size();
        if (N == 0) return 0;
        vector<int> lastRightPos(256, -1);
        for (int i = 0; i < N; ++i) lastRightPos[patten[i]] = i;

        // matching
        for (int i = 0, skip = 0; i <= M - N; i += skip) {
            skip = 0;
            for (int j = N - 1; j >= 0; --j) {
                if (str[i + j] != patten[j]) {
                    int distance = j - lastRightPos[str[i + j]];
                    skip = distance > 1 ? distance : 1;
                }
            }
            if (!skip) return i;
        }
        return -1;
    }

    // Sunday
    // time O(N)~worst O(M*N) space O(1)
    // runtime ~0 100%
    int strStr_3(const string &str, const string &patten) {
        int M = str.size(), N = patten.size();
        if (N == 0) return 0;
        if (M < N) return -1;
        for (int i = 0; i <= M - N;) {
            if (str[i] == patten[0]) {
                int j = 1;
                for (; j < N; j++)
                    if (patten[j] != str[i + j]) break;
                if (j == N) return i;
                i++;
            } else {
                i += sundayProcess(str[i + N], patten);
            }
        }
        return -1;
    }

    int sundayProcess(char c, const string &patten) {
        for (int i = patten.size() - 1, idx = 0; i >= 0; --i, ++idx)
            if (patten[i] == c) return idx + 1;

        return patten.size() + 1;
    }
};

int main() {
    Solution s;
    int ans = s.strStr("aaa", "aaa");
    return 0;
}