#include <string>

using std::string;

class Solution {
  public:
    string longestPalindrome(string s) {
        int len = 0, i, j, k, t, start;

        for (i = 0; i < s.size(); ++i) {
            for (j = i - 1, k = i + 1; j >= 0 && k < s.size() && s[j] == s[k];
                 j--, k++)
                ;
            j++, k--;
            if ((t = k - j + 1) > len) {
                len = t;
                start = j;
            }

            for (j = i, k = i + 1; j >= 0 && k < s.size() && s[j] == s[k];
                 j--, k++)
                ;
            j++, k--;
            if ((t = k - j + 1) > len) {
                len = t;
                start = j;
            }
        }
        if (len == 0)
            return(string(""));
        return(string(s, start, len));
    }
};

int main(void){}
