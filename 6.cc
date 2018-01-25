#include <string>

using std::string;

class Solution {
  public:
    string convert(string s, int numRows) {
        string res(s);
        int i, j, p = 0, c = 2 * numRows - 2;

        if (numRows == 1)
            return(res);

        for (i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows - 1) {
                for (j = i; j < s.size(); j += c)
                    res[p++] = s[j];
                continue;
            }

            for (j = i; j < s.size(); ) {
                res[p++] = s[j];
                if ((j += c - 2 * i) < s.size())
                    res[p++] = s[j];
                j += 2 * i;
            }
        }

        return(res);
    }
};

int main(void){}
