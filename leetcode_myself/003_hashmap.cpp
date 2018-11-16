#include <iostream>

int lengthOfLongestSubstring(const char *s) {
    if (s == NULL || *s == '\0') return 0;

    int len = strlen(s);
    if (len == 1)
        return 1;
    else if (len == 2) {
        if (s[0] == s[1])
            return 1;
        else
            return 2;
    }
    int maxLen = 0;
    int hashArray[256] = {0};
    for (int firstPos = 0; firstPos < len; firstPos++) {
        hashArray[s[firstPos]] = 1;
        int breakFlag = 0;
        int secPos = firstPos + 1;
        for (; secPos < len; secPos++) {
            if (hashArray[s[secPos]] == 0) {
                hashArray[s[secPos]] = 1;
            } else {
                if (secPos - firstPos > maxLen) {
                    maxLen = secPos - firstPos;
                }
                breakFlag = 1;
                break;
            }
        }
        if (!breakFlag && secPos - firstPos > maxLen)
            maxLen = secPos - firstPos;

        if (maxLen > len - firstPos || maxLen > 95) break;
        memset(hashArray, 0, sizeof(hashArray));
    }
    return maxLen;
}

int main() {
    using std::cout;
    using std::endl;
    char s[] = "dvdf";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}