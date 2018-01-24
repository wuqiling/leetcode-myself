#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*3��ѭ����Ч������*/

//TODO:���ص����飬�ڴ���䷽ʽ���Ż�������
char *longestPalindrome(char *s)
{
	char *strResult = NULL;
	int sLen = strlen(s);
	if (sLen == 0 || sLen == 1)
	{
		return s;
	}
	//������ַ�����ʼ����
	//һ��������ߣ�һ�������ұ�
	char *p = s, *q = s;
	int tmpLen = sLen;
	int equFlag = 0, compareLen = 0;
	for (int i = 0; i < sLen; i++)
	{
		tmpLen = sLen - i;
		for (int j = 0; j < i + 1; j++)
		{
			p = s + j;
			q = s + (tmpLen / 2 + j + (tmpLen & 0x01));
			equFlag = 1;
			compareLen = tmpLen >> 1;
			for (int k = 0; k < compareLen; k++)
			{
				if (p[k] != q[compareLen - k - 1])
				{
					equFlag = 0;
					break;
				}
			}

			if (equFlag)
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