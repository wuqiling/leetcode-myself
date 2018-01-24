#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*根据条件最多长度95，使用笨拙的方法进行测试，效率 80%*/

#if 0
//////////////////////////////////////////////////////////////////////////

int lengthOfLongestSubstring(char* s) {
	int cntMax = 1, cntmp = 1, flag = 0;
	char *tmp;
	char *pstart;
	char *pend;
	/**
	* check if *s = null
	*/
	if (s == NULL || *s == '\0') {
		return 0;
	}
	/**
	* find the max length
	*/
	pend = pstart = s;
	/**
	* tmp is a string for compare
	*/
	tmp = (char *)malloc(strlen(s) + 1);
	if (tmp == NULL) {
		return 0;
	}
	while (1) {
		/**
		* when flag=1
		* means found equal char
		*/
		if (flag) {
			if (++s == '\0')
				break;
			flag = 0;
			cntmp = 1;
			pend = pstart = s;
		}
		pend++;
		if (*pend == '\0') {
			break;
		}
		/**
		* check if *pend is in pstart to pend-1
		*/
		strcpy_s(tmp, pstart);
		tmp[pend - pstart] = '\0';
		/**
		* not found
		*/
		if (strchr(tmp, *pend) == NULL) {
			flag = 0;
			cntmp++;
			cntMax = cntMax < cntmp ? cntmp : cntMax;

			/**
			* max of cntMax is 95
			*/
			if (cntMax == 95)
				break;
		}
		else {
			flag = 1;
		}
	}
	free(tmp);
	return cntMax;
}


//////////////////////////////////////////////////////////////////////////
#endif