#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    if (s == NULL || *s == '\0') return 0;
    int hash[256] = {0};
    int begin = 0, end = 0;  // two pointer
    int repeart = 0, res = 0;
    int N = strlen(s);
    for (; end < N; end++) {
        if (hash[s[end]]++ > 0) {
            repeart++;
        }
        while (repeart > 0) {
            if (hash[s[begin]] > 1) {
                repeart--;
            }
            hash[s[begin]]--;
            begin++;
        }
        res = MAX(res, end - begin + 1);
    }
    return res;
}

int main(int argc, char const* argv[]) {
    printf("%s:%d\n", lengthOfLongestSubstring("aaaa"));
    return 0;
}
