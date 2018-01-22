#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*最简单的方法，使用两次迭代，效率极低 10% */

//////////////////////////////////////////////////////////////////////////
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target) {
	/**
	* allocate memory for indexps
	*/
	int *indexp = NULL;
	indexp = (int *)malloc(sizeof(int));
	/**
	* check if nums == null or alloc error
	*/
	if (indexp == NULL) {
		return NULL;
	}
	if (nums == NULL) {
		free(indexp);
		return NULL;
	}

	/**
	* found the index
	*/
	for (int i = 0; i < numsSize; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				indexp[0] = i;
				indexp[1] = j;
				return indexp;
			}
		}
	}
	free(indexp);
	return NULL;
}
