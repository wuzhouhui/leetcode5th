#include <limits.h>

int myAtoi(char *str)
{
	long int res = 0;
	int sign = 1;

	while (*str && isblank(*str))
		str++;
	if (*str && *str == '+')
		str++;
	else if (*str && *str == '-') {
		sign = -1;
		str++;
	}
	while (*str && isdigit(*str)) {
		res = res * 10 + *str++ - '0';
		if (res >= UINT_MAX)
			break;
	}

	res *= sign;
	if (res <= INT_MIN)
		return(INT_MIN);
	if (res >= INT_MAX)
		return(INT_MAX);
	return((int)res);
}
main(){}
