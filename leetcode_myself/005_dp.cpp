#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestPalindrome(char *s) {
    assert(s != NULL);
    int N = strlen(s);
    if (N <= 1) return s;
    // use pNN[i][j] to dynamic programming
    char *pNN = (char *)malloc(N * N);
    if (pNN == NULL) return NULL;
    memset(pNN, 0, N * N);
    int maxleft = 0;
    int maxL = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j >= 0; j--) {
            if (s[j] == s[i] && (i - j < 2 || pNN[(j + 1) * N + i - 1])) {
                pNN[j * N + i] = 1;
                if (i - j + 1 > maxL) {
                    maxL = i - j + 1;
                    maxleft = j;
                }
            }
        }
    }
    free(pNN);
    pNN = NULL;
    char *strResult = (char *)malloc(maxL + 1);
    if (strResult == NULL) {
        return NULL;
    }
    strncpy(strResult, s + maxleft, maxL);
    strResult[maxL] = '\0';
    return strResult;
}

int main() {
    char p[] = "dddddddd";
    printf("%s", longestPalindrome(p));
    return 0;
}