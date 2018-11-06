#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxArea(int *height, int heightSize)
{
	assert(height != NULL && heightSize > 1);
	int maxContainer = 0;
	int minheight = 0;
	int maxArea = 0;
	for (int i = 0; i < heightSize; i++)
	{
		for (int j = heightSize - 1; j > i; j--)
		{
			minheight = MIN(height[i], height[j]);
			maxArea = (j - i) * minheight;
			if (maxArea > maxContainer)
				maxContainer = maxArea;
		}
	}
	return maxContainer;
}

int main()
{
	int a[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int N = sizeof(a) / sizeof(a[0]);
	maxArea(a, N);
	return 0;
}