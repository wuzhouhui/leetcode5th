#include <limits.h>

int reverse(int x)
{
	if (x == INT_MIN)
		return(0);

	long int res = 0;
	int sign = 1;

	if (x < 0) {
		x = -x;
		sign = -1;
	}

	while (x) {
		res = res * 10 + x % 10;
		x /= 10;
	}
	res *= sign;

	if (res > INT_MAX || res < INT_MIN)
		return(0);
	return((int)res);
}
main(){}
