#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
  public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        string ans;

        do_comb(digits, 0, res, ans);
        return(res);
    }

  private:
    void do_comb(string &digits, int start, vector<string> &res, string &ans)
    {
        static char tbl[][5] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };
        if (start >= digits.size()) {
            if (ans.size() > 0)
                res.push_back(ans);
            return;
        }

        int idx = digits[start] - '0';
        if (idx == 0 || idx == 1)
            do_comb(digits, start + 1, res, ans);
        else
            for (int i = 0; tbl[idx][i]; i++) {
                ans.push_back(tbl[idx][i]);
                do_comb(digits, start + 1, res, ans);
                ans.erase(ans.size() - 1, 1);
            }
    }
};

int main(void){}
