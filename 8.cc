#include <cctype>
#include <climits>
#include <cstdint>
#include <string>

using std::string;

class Solution {
  public:
    int myAtoi(string str)
    {
        int64_t res = 0;
        int sign = 1;
        auto ite = str.begin();

        while (ite != str.end() && isspace(*ite))
            ++ite;
        if (ite != str.end() && *ite == '-') {
            sign = -1;
            ++ite;
        } else if (ite != str.end() && *ite == '+')
            ++ite;

        while (ite != str.end() && isdigit(*ite)) {
            res = res * 10 + *ite - '0';
            ++ite;
            if (res * sign < INT_MIN || res * sign > INT_MAX)
                break;
        }
        res *= sign;
        if (res < INT_MIN)
            return(INT_MIN);
        if (res > INT_MAX)
            return(INT_MAX);
        return((int)res);
    }
};

int main(void){}
