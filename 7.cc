#include <climits>
#include <cstdint>

class Solution {
  public:
    int reverse(int x)
    {
        int64_t lx = x, res = 0;
        int sign = 1;

        if (lx < 0) {
            sign = -1;
            lx = -lx;
        }

        while (lx) {
            res = res * 10 + (lx % 10);
            if (res * sign > INT_MAX || res * sign < INT_MIN)
                break;
            lx /= 10;
        }

        res *= sign;
        if (res < INT_MIN || res > INT_MAX)
            return(0);
        else
            return((int)res);
    }
};

int main(void){}
