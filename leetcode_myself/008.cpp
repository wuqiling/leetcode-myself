#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int myAtoi(char *str)
{
	if (str == NULL)
		return 0;
	int64_t result = 0;
	int isNeg = 0;
	/************************************************************************/
	/* move str                                                              */
	/************************************************************************/
	while (*str != '\0')
	{
		if (*str == ' ')
			str++;
		else
			break;
	}
	if (*str == '-')
	{
		isNeg = 1;
		str++;
	}
	else if (*str == '+')
	{
		isNeg = 0;
		str++;
	}
	else if (*str == '\0' || *str < '0' || *str > '9')
	{
		return 0;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			result = result * 10 + *str - '0';
			if (result > INT_MAX)
			{
				return isNeg ? INT_MIN : INT_MAX;
			}
		}
		else
		{
			break;
		}
		str++;
	}
	return isNeg ? -1 * result : result;
}

int main()
{
	printf("%d", myAtoi("-91283472332"));
	return 0;
}