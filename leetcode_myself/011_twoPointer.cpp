#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int maxArea(int *height, int heightSize)
{
	assert(height != NULL && heightSize > 1);
	int curContainer = 0;
	int maxArea = 0;
	int begin = 0, end = heightSize - 1;
	while (begin < end)
	{
		if (height[begin] > height[end])
		{
			curContainer = (end - begin) * height[end];
			if (curContainer > maxArea)
				maxArea = curContainer;
			end--;
		}
		else
		{
			curContainer = (end - begin) * height[begin];
			if (curContainer > maxArea)
				maxArea = curContainer;
			begin++;
		}
	}
	return maxArea;
}

int main()
{
	int a[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int N = sizeof(a) / sizeof(a[0]);
	maxArea(a, N);
	return 0;
}