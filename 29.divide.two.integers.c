#include <limits.h>
#include <stdlib.h>

int divide(int dividend, int divisor)
{
	if (divisor == 0)
		return(dividend < 0 ? INT_MIN : INT_MAX);
	if (dividend == INT_MIN && divisor == -1)
		return(INT_MAX);
	int sign, res, i;
	long int ldend, ldsor;

	if ((dividend < 0) ^ (divisor < 0))
		sign = -1;
	else
		sign = 1;
	ldend = labs(dividend);
	ldsor = labs(divisor);
	res = 0;
	while (ldend >= ldsor) {
		for (i = 0; (ldsor << i) <= ldend; i++)
			;
		i--;
		res += 1 << i;
		ldend -= ldsor << i;
	}
	return(res * sign);
}
main(){}
