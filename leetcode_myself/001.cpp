#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*��򵥵ķ�����ʹ�����ε���*/

//////////////////////////////////////////////////////////////////////////
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    if (nums == NULL) return NULL;

    // found the index
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* indexp = (int*)malloc(2 * sizeof(int));
                if (indexp == NULL) return NULL;
                indexp[0] = i;
                indexp[1] = j;
                return indexp;
            }
        }
    }
    return NULL;
}
