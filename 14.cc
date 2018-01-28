#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
  public:
    static bool mstrcmp(const string &s1, const string &s2)
    {
        return(s1.compare(s2));
    }

    string longestCommonPrefix(vector<string> &strs)
    {
        int max = -1;

        if (strs.size() == 0)
            return(string(""));
        if (strs.size() == 1)
            return(string(strs[0]));

        stable_sort(strs.begin(), strs.end(), mstrcmp);
        for (auto i = strs.begin(); i + 1 != strs.end(); ++i) {
            int t = commlen(*i, *(i + 1));
            if (max < 0 || t < max)
                max = t;
        }
        return(string(strs[0], 0, max));
    }

  private:
    int commlen(const string &s1, const string &s2)
    {
        int l = 0;
        for (auto i = s1.begin(), j = s2.begin();
                i != s1.end()
                && j != s2.end()
                && *i == *j; ++i, ++j, ++l)
            ;
        return(l);
    }
};

int main(void){}
