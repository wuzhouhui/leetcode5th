#include <climits>

class Solution {
  public:
    int divide(int dividend, int divisor)
    {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return(INT_MAX);

        long res = 0, ldividend, ldivisor;
        long int i, sign = 1;

        ldividend = dividend;
        ldivisor = divisor;
        if (ldividend < 0)
            ldividend = -ldividend;
        if (ldivisor < 0)
            ldivisor = -ldivisor;
        if ((dividend < 0) ^ (divisor < 0))
            sign = -1;

        while (ldividend >= ldivisor) {
            for (i = 0; (ldivisor << i) <= ldividend; i++)
                ;
            i--;
            res += 1L << i;
            ldividend -= ldivisor << i;
        }

        res *= sign;
        if (res < INT_MIN)
            return(INT_MAX);
        else if (res >= INT_MAX)
            return(INT_MAX);
        else
            return((int)res);
    }
};

int main(void){}
