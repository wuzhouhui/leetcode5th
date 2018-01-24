#include <string>

using std::string;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int cnt[256] = { 0 };
        decltype(s.size()) i, j, t, res = 0;

        for (i = j = 0; i != s.size(); ++i) {
            if (++cnt[s[i]] == 2) {
                if ((t = i - j) > res)
                    res = t;
                while (--cnt[s[j++]] != 1)
                    ;
            }
        }
        if ((t = i - j) > res)
            res = t;
        return((int)res);
    }
};

int main(void) { }
