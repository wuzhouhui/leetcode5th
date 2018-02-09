#include <string>

using std::string;
using std::to_string;

class Solution {
  public:
    string countAndSay(int n)
    {
        if (n <= 0)
            return(string(""));
        string res("1");
        int cn = 0;
        char prev = 0;

        for (int i = 2; i <= n; i++) {
            string tmp = "";
            cn = 0;
            prev = 0;
            for (int j = 0; j < res.size(); j++) {
                if (j == 0 || res[j] == prev) {
                    prev = res[j];
                    cn++;
                } else {
                    tmp += to_string(cn) + prev;
                    cn = 1;
                    prev = res[j];
                }
            }
            if (cn)
                tmp += to_string(cn) + prev;
            res = tmp;
        }
        return(res);
    }
};

int main(void){}
