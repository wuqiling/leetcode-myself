#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*3层循环，效果极差*/

//检测两个字符串是否对称,指定输入的字符串长度
//对称返回 0
//否则返回 -1
//输入两个都为空时 返回 0
int compareTwoString_n(char *s1, char *s2, int sLen)
{
	for (int i = 0; i < sLen; i++)
	{
		if (s1[i] != s2[sLen - i - 1])
		{
			return -1;
		}
	}
	return 0;
}

char *longestPalindrome(char *s)
{
	char *strResult = NULL;
	int sLen = strlen(s);
	if (sLen == 0 || sLen == 1)
	{
		return s;
	}
	//从最长的字符串开始找起
	//一个查找左边，一个查找右边
	char *p = s, *q = s;
	int tmpLen = sLen;
	for (int i = 0; i < sLen; i++)
	{
		tmpLen = sLen - i;
		for (int j = 0; j < i + 1; j++)
		{
			p = s + j;
			q = s + (tmpLen / 2 + j + (tmpLen & 0x01));
			if (compareTwoString_n(p, q, tmpLen / 2) == 0)
			{
				strResult = (char *)malloc((tmpLen + 1) * sizeof(char));
				if (strResult == NULL)
				{
					return NULL;
				}
				memset(strResult, 0, tmpLen + 1);
				strncpy(strResult, p, tmpLen);
				return strResult;
			}
		}
	}
	strResult = (char *)malloc(2 * sizeof(char));
	if (strResult == NULL)
	{
		return NULL;
	}
	strncpy(strResult, s, 1);
	return strResult;
}